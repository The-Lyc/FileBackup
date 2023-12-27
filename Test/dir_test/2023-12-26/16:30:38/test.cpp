#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>


int main() {
    
    const std::string fp = "/home/lyc/cpp_ws/file_backup/test/doc/s2_test";
    const char* filePath = fp.c_str();

    struct stat stat_buf;
    int ret = lstat(filePath, &stat_buf);

    std::cout<< S_ISREG(stat_buf.st_mode ) <<std::endl;
}
