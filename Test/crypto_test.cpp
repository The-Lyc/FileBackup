#include "../include/crypto.h"

int main() {
    // std::string password = getUserPassword();
    std::string password = "123456" ;
    SecByteBlock key = generateKey(password);

    std::string inputFile = "test.txt";
    std::string encryptedFile = "/home/lyc/workspace/tmp/test.dat";
    // std::string encryptedFile = "/home/lyc/cpp_ws/file_backup/test/build/test_encrypted.dat";
    std::string decryptedFile = "test_decrypted.txt";

    // std::fstream tmp(encryptedFile);

    // encryptFile(inputFile, encryptedFile, key);
    // std::cout << "文件加密成功。" << std::endl;

    decryptFile(encryptedFile, decryptedFile, key);
    std::cout << "文件解密成功。" << std::endl;

    // tmp.close();

    return 0;
}