/**
 * OS-Nexus-Studio File Server
 * TCP-based multi-client file server with LIST, GET, and INFO commands
 * Cross-platform compatible (Windows/MinGW/GCC)
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <sys/stat.h>

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
    #define CLOSE_SOCKET closesocket
    #define SOCKET_ERROR_CODE WSAGetLastError()
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <dirent.h>
    #define CLOSE_SOCKET close
    #define SOCKET_ERROR_CODE errno
    #define INVALID_SOCKET -1
    typedef int SOCKET;
#endif

#define PORT 9091
#define BUFFER_SIZE 4096

using namespace std;

struct ClientInfo {
    SOCKET sock;
    sockaddr_in addr;
};

string getCurrentTime() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    stringstream ss;
    ss << put_time(ltm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

bool sendResponse(SOCKET sock, const string& response) {
#ifdef _WIN32
    if (send(sock, response.c_str(), response.size(), 0) == SOCKET_ERROR) {
#else
    if (send(sock, response.c_str(), response.size(), 0) == -1) {
#endif
        cerr << "Send failed" << endl;
        return false;
    }
    return true;
}

string formatFileSize(long long bytes) {
    if (bytes < 1024) return to_string(bytes) + " B";
    if (bytes < 1024 * 1024) return to_string(bytes / 1024) + " KB";
    return to_string(bytes / (1024 * 1024)) + " MB";
}

string listDirectory() {
    string response = "=== Available Files ===\n";
    
#ifdef _WIN32
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA("*", &findData);
    
    if (hFind == INVALID_HANDLE_VALUE) {
        response += "No files found.\n";
        return response;
    }
    
    int count = 0;
    do {
        if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            long long fileSize = findData.nFileSizeLow;
            string sizeStr = formatFileSize(fileSize);
            
            // Get time manually
            FILETIME ft = findData.ftLastWriteTime;
            SYSTEMTIME st;
            FileTimeToSystemTime(&ft, &st);
            char timeBuf[64];
            snprintf(timeBuf, sizeof(timeBuf), "%04d-%02d-%02d %02d:%02d",
                st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute);
            
            response += "  [" + to_string(++count) + "] " + findData.cFileName;
            response += " (" + sizeStr + ") - " + timeBuf + "\n";
        }
    } while (FindNextFileA(hFind, &findData));
    FindClose(hFind);
#else
    DIR* dir = opendir(".");
    if (!dir) {
        response += "Cannot open directory.\n";
        return response;
    }
    
    int count = 0;
    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        if (entry->d_type == DT_REG) {
            struct stat st;
            if (stat(entry->d_name, &st) == 0) {
                string sizeStr = formatFileSize(st.st_size);
                tm* ltm = localtime(&st.st_mtime);
                char timeBuf[64];
                snprintf(timeBuf, sizeof(timeBuf), "%04d-%02d-%02d %02d:%02d",
                    ltm->tm_year + 1900, ltm->tm_mon + 1, ltm->tm_mday,
                    ltm->tm_hour, ltm->tm_min);
                
                response += "  [" + to_string(++count) + "] " + entry->d_name;
                response += " (" + sizeStr + ") - " + timeBuf + "\n";
            }
        }
    }
    closedir(dir);
#endif
    
    if (count == 0) {
        response += "No files found.\n";
    } else {
        response += "\nTotal files: " + to_string(count) + "\n";
    }
    
    return response;
}

string getFileInfo(const string& filename) {
    struct stat st;
    
#ifdef _WIN32
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA(filename.c_str(), &findData);
    
    if (hFind == INVALID_HANDLE_VALUE) {
        return "ERROR: File not found - " + filename;
    }
    
    FindClose(hFind);
    
    if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
        return "ERROR: Path is a directory - " + filename;
    }
    
    stringstream ss;
    ss << "=== File Information ===" << "\n";
    ss << "Name: " << findData.cFileName << "\n";
    ss << "Size: " << findData.nFileSizeLow << " bytes (" 
       << (findData.nFileSizeLow / 1024.0) << " KB)\n";
    
    ss << "Attributes: ";
    if (findData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) ss << "READONLY ";
    if (findData.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) ss << "HIDDEN ";
    if (findData.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM) ss << "SYSTEM ";
    ss << "\n";
    
    FILETIME ft = findData.ftLastWriteTime;
    SYSTEMTIME st_sys;
    FileTimeToSystemTime(&ft, &st_sys);
    char timeStr[64];
    snprintf(timeStr, sizeof(timeStr), "%04d-%02d-%02d %02d:%02d:%02d",
        st_sys.wYear, st_sys.wMonth, st_sys.wDay, st_sys.wHour, st_sys.wMinute, st_sys.wSecond);
    ss << "Modified: " << timeStr << "\n";
#else
    if (stat(filename.c_str(), &st) != 0) {
        return "ERROR: File not found - " + filename;
    }
    
    if (S_ISDIR(st.st_mode)) {
        return "ERROR: Path is a directory - " + filename;
    }
    
    stringstream ss;
    ss << "=== File Information ===" << "\n";
    ss << "Name: " << filename << "\n";
    ss << "Size: " << st.st_size << " bytes (" << (st.st_size / 1024.0) << " KB)\n";
    ss << "Permissions: " << oct << (st.st_mode & 0777) << "\n";
    
    tm* ltm = localtime(&st.st_mtime);
    char timeBuf[64];
    snprintf(timeBuf, sizeof(timeBuf), "%04d-%02d-%02d %02d:%02d:%02d",
        ltm->tm_year + 1900, ltm->tm_mon + 1, ltm->tm_mday,
        ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    ss << "Modified: " << timeBuf << "\n";
#endif
    return ss.str();
}

bool sendFile(SOCKET sock, const string& filename) {
    ifstream file(filename, ios::binary);
    
    if (!file.is_open()) {
        sendResponse(sock, "ERROR: Cannot open file - " + filename);
        return false;
    }
    
    // Send header
    stringstream header;
    header << "FILE_START|" << filename << "|" << endl;
    sendResponse(sock, header.str());
    
    // Send file content in chunks
    char buffer[BUFFER_SIZE];
    
    while (file.read(buffer, BUFFER_SIZE)) {
        streamsize bytesRead = file.gcount();
#ifdef _WIN32
        if (send(sock, buffer, bytesRead, 0) == SOCKET_ERROR) {
#else
        if (send(sock, buffer, bytesRead, 0) == -1) {
#endif
            file.close();
            return false;
        }
    }
    
    if (file.gcount() > 0) {
#ifdef _WIN32
        if (send(sock, buffer, file.gcount(), 0) == SOCKET_ERROR) {
#else
        if (send(sock, buffer, file.gcount(), 0) == -1) {
#endif
            file.close();
            return false;
        }
    }
    
    file.close();
    sendResponse(sock, "\nFILE_END");
    
    return true;
}

void handleClient(SOCKET sock, sockaddr_in* clientAddr) {
    char clientIP[INET_ADDRSTRLEN];
    
#ifdef _WIN32
    strncpy(clientIP, inet_ntoa(clientAddr->sin_addr), INET_ADDRSTRLEN - 1);
    clientIP[INET_ADDRSTRLEN - 1] = '\0';
#else
    inet_ntop(AF_INET, &(clientAddr->sin_addr), clientIP, INET_ADDRSTRLEN);
#endif
    
    cout << "[" << getCurrentTime() << "] Client connected: " << clientIP << endl;
    
    char buffer[BUFFER_SIZE];
    int bytesReceived;
    
    while (true) {
#ifdef _WIN32
        bytesReceived = recv(sock, buffer, BUFFER_SIZE - 1, 0);
        if (bytesReceived == SOCKET_ERROR) {
            if (WSAGetLastError() == WSAEWOULDBLOCK) {
                Sleep(100);
                continue;
            }
            cout << "[" << getCurrentTime() << "] Client disconnected (error)" << endl;
            break;
        }
#else
        bytesReceived = recv(sock, buffer, BUFFER_SIZE - 1, 0);
        if (bytesReceived == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                usleep(100000);
                continue;
            }
            cout << "[" << getCurrentTime() << "] Client disconnected (error)" << endl;
            break;
        }
#endif
        
        if (bytesReceived == 0) {
            cout << "[" << getCurrentTime() << "] Client disconnected: " << clientIP << endl;
            break;
        }
        
        buffer[bytesReceived] = '\0';
        string command(buffer);
        
        // Trim whitespace
        size_t start = command.find_first_not_of(" \r\n\t");
        size_t end = command.find_last_not_of(" \r\n\t");
        if (start != string::npos && end != string::npos) {
            command = command.substr(start, end - start + 1);
        } else {
            command = "";
        }
        
        cout << "[" << getCurrentTime() << "] Command from " << clientIP << ": " << command << endl;
        
        if (command == "LIST") {
            sendResponse(sock, listDirectory());
        }
        else if (command.substr(0, 4) == "GET ") {
            string filename = command.substr(4);
            size_t start = filename.find_first_not_of(" \r\n\t");
            size_t end = filename.find_last_not_of(" \r\n\t");
            if (start != string::npos && end != string::npos) {
                filename = filename.substr(start, end - start + 1);
            } else {
                filename = "";
            }
            
            cout << "[" << getCurrentTime() << "] Sending file: " << filename << endl;
            
            if (!sendFile(sock, filename)) {
                cout << "[" << getCurrentTime() << "] Failed to send file: " << filename << endl;
            }
        }
        else if (command.substr(0, 5) == "INFO ") {
            string filename = command.substr(5);
            size_t start = filename.find_first_not_of(" \r\n\t");
            size_t end = filename.find_last_not_of(" \r\n\t");
            if (start != string::npos && end != string::npos) {
                filename = filename.substr(start, end - start + 1);
            } else {
                filename = "";
            }
            
            sendResponse(sock, getFileInfo(filename));
        }
        else if (command == "HELP") {
            string response = 
                "=== File Server Commands ===\n"
                "LIST           - List all files\n"
                "GET <filename> - Download a file\n"
                "INFO <filename> - Get file info\n"
                "HELP           - Show help\n"
                "QUIT           - Disconnect\n";
            sendResponse(sock, response);
        }
        else if (command == "QUIT" || command == "EXIT") {
            sendResponse(sock, "Goodbye!\n");
            break;
        }
        else {
            sendResponse(sock, "ERROR: Unknown command. Type HELP for available commands.\n");
        }
    }
    
    CLOSE_SOCKET(sock);
}

#ifdef _WIN32
DWORD WINAPI clientThread(LPVOID lpParam) {
    ClientInfo* client = (ClientInfo*)lpParam;
    handleClient(client->sock, &client->addr);
    delete client;
    return 0;
}
#else
void* clientThread(void* param) {
    ClientInfo* client = (ClientInfo*)param;
    handleClient(client->sock, &client->addr);
    delete client;
    return nullptr;
}
#endif

int main() {
    cout << "========================================" << endl;
    cout << "    OS-Nexus-Studio File Server" << endl;
    cout << "========================================" << endl;
    
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup failed" << endl;
        return 1;
    }
#endif
    
    SOCKET server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == INVALID_SOCKET) {
        cerr << "Socket creation failed" << endl;
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }
    
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    int opt = 1;
#ifdef _WIN32
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (const char*)&opt, sizeof(opt));
#else
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
#endif
    
    if (bind(server_fd, (sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        cerr << "Bind failed" << endl;
        CLOSE_SOCKET(server_fd);
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }
    
    if (listen(server_fd, 10) == SOCKET_ERROR) {
        cerr << "Listen failed" << endl;
        CLOSE_SOCKET(server_fd);
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }
    
    cout << "[" << getCurrentTime() << "] Server started on port " << PORT << endl;
    cout << "[" << getCurrentTime() << "] Listening for connections..." << endl;
    cout << "\nAvailable Commands:" << endl;
    cout << "  LIST           - List files" << endl;
    cout << "  GET <filename> - Download file" << endl;
    cout << "  INFO <filename> - Get file info" << endl;
    cout << "  HELP           - Show help" << endl;
    cout << "  QUIT           - Disconnect" << endl;
    cout << "\nPress Ctrl+C to stop\n" << endl;
    
    int clientCount = 0;
    
    while (true) {
        sockaddr_in clientAddr;
        socklen_t addrLen = sizeof(clientAddr);
        
        SOCKET new_socket = accept(server_fd, (sockaddr*)&clientAddr, &addrLen);
        
        if (new_socket == INVALID_SOCKET) {
            continue;
        }
        
        ClientInfo* client = new ClientInfo();
        client->sock = new_socket;
        client->addr = clientAddr;
        
#ifdef _WIN32
        DWORD threadId;
        HANDLE hThread = CreateThread(NULL, 0, clientThread, client, 0, &threadId);
        if (hThread) CloseHandle(hThread);
#else
        pthread_t threadId;
        pthread_create(&threadId, NULL, clientThread, client);
        pthread_detach(threadId);
#endif
        else {
            CLOSE_SOCKET(new_socket);
            delete client;
        }
        
        clientCount++;
    }
    
    CLOSE_SOCKET(server_fd);
#ifdef _WIN32
    WSACleanup();
#endif
    
    return 0;
}
