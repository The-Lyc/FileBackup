#include <cstring>
#include <iostream>
#include <iomanip>
#include <filesystem>
#include <unistd.h>
#include <chrono> 
#include <iomanip>
#include <sys/stat.h>

namespace fs = std::filesystem;

void printTree(const fs::path& path, int level = 0) {

    std::string path_string{path.u8string()};

    char ps[path_string.length()+1];
    strcpy(ps, path_string.c_str()); 

    const char* filename = ps;
    struct stat file_info;
    char time_str[20];

    if (stat(filename, &file_info) == 0) {
        // 获取最后修改时间
        std::time_t modification_time = file_info.st_mtime;

        // 转换为本地时间
        struct tm *tm_info = localtime(&modification_time);

        // 格式化输出
        
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_info);

        // std::cout << "File last modified at: " << time_str << std::endl;
    } else {
        std::cerr << "Error getting file information for " << filename << std::endl;
        return;
    }

    if (fs::exists(path) && fs::is_directory(path)) {
        // 打印当前目录
        std::cout << std::setw(level * 4) << "" << "+ " << path.filename() << " (Dir)" << time_str << std::endl;

        // 遍历当前目录
        for (const auto& entry : fs::directory_iterator(path)) {
            printTree(entry.path(), level + 1);
        }
    } else {
        // 打印文件
        std::cout << std::setw(level * 4) << "" << "- " << path.filename() << " (File)" << time_str << std::endl;
    }
}

int main() {
    const size_t bufferSize = 1024;
    char buffer[bufferSize];
    getcwd(buffer, bufferSize);

    std::string startPath = buffer;  // 替换为你想要显示的目录路径
    fs::path path(startPath);

    if (fs::exists(path) && fs::is_directory(path)) {
        std::cout << "Directory Tree for: " << path << std::endl;
        printTree(path);
    } else {
        std::cerr << "Invalid directory path." << std::endl;
        return 1;
    }

    return 0;
}
