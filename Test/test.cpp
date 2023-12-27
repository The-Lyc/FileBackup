#include "../include/huffman.h"

int main()
{
    std::string sourcePath = "/home/lyc/cpp_ws/file_backup/Test/huffman.txt" ;
    std::string tempPath =  "/home/lyc/cpp_ws/file_backup/Test/tmp/huffman.txt" ;
    std::string destPath = "huffman.txt" ;

    zipToCode(sourcePath,tempPath);

    recoverFromCode(tempPath,destPath);

}
