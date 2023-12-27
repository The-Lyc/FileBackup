#include "../include/search.h"

namespace fs = std::filesystem;

extern void printTree(const fs::path& path, int level ) {

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
}&