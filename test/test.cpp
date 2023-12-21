#include <iostream>
#include <unistd.h>
#include <limits.h> // 用于 PATH_MAX 定义
#include <libgen.h> // 用于 dirname 函数
#include <cstring>

std::string getSymlinkRelativePath(const char* symlinkPath) {
    char absolutePath[PATH_MAX];
    
    // 通过 realpath 获取软链接的绝对路径
    char* resolvedPath = realpath(symlinkPath, absolutePath);
    std::cout<<resolvedPath<<std::endl;
    if (resolvedPath == nullptr) {
        perror("realpath");
        return "";
    }

    // 使用 dirname 获取目录部分
    char dirName[PATH_MAX];
    strncpy(dirName, dirname(resolvedPath), sizeof(dirName));
    dirName[sizeof(dirName) - 1] = '\0';

    // 计算相对路径
    char relativePath[PATH_MAX];
    if (realpath(dirName, relativePath) == nullptr) {
        perror("realpath");
        return "";
    }

    return relativePath;
}

int main() {
    const char* symlinkPath = "/home/lyc/cpp_ws/file_backup/test/doc/s_test";

    std::string symlinkRelativePath = getSymlinkRelativePath(symlinkPath);

    if (!symlinkRelativePath.empty()) {
        std::cout << "Relative path of symbolic link itself: " << symlinkRelativePath << std::endl;
    } else {
        std::cerr << "Error getting symbolic link's relative path." << std::endl;
        return 1;
    }

    return 0;
}
