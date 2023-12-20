#include "../include/search.h"

namespace fs = std::filesystem;

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