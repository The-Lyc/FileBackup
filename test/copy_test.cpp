#include "../include/copy.h"

int main() {
    fs::path source_path("/home/lyc/cpp_ws/file_backup/test/doc");
    fs::path destination_path("/home/lyc/cpp_ws/file_backup/test/dir_test");

    copy_directory(source_path, destination_path);

    return 0;
}

