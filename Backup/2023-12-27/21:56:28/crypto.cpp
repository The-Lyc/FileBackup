#include "../include/crypto.h"

using namespace CryptoPP;

// 禁用终端回显
void disableEcho() {
    termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

// 启用终端回显
void enableEcho() {
    termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

// 获取用户输入的密码
std::string getUserPassword() {
    std::string password_1;
    std::string password_2;
    // 禁用终端回显
    disableEcho();
    std::cout << "Enter password: "<<std::endl;
    std::getline(std::cin, password_1);
    std::cout << "Verify password: "<<std::endl;
    std::getline(std::cin, password_2);
    // 启用终端回显
    enableEcho();
    if(password_1 == password_2) {
        std::cout<<"Password set successfully"<< std::endl;
    }
    else {
        std::cout<<"Different Passwords,retry"<< std::endl;
        getUserPassword();
        return NULL;
    }
    return password_1;
}

// 生成密钥
SecByteBlock generateKey(const std::string& password) {
    SecByteBlock key(AES::DEFAULT_KEYLENGTH);
    PKCS5_PBKDF2_HMAC<SHA256> pbkdf;
    pbkdf.DeriveKey(key, key.size(), 0, (const byte*)password.data(), password.size(), nullptr, 0 , 1000);
    return key;
}

// 加密文件
void encryptFile(const std::string& inputFile, const std::string& outputFile, const SecByteBlock& key) {
    try {
        CBC_Mode<AES>::Encryption encryptor;
        encryptor.SetKeyWithIV(key, key.size(), key);

        FileSource(inputFile.c_str(), true,
                   new StreamTransformationFilter(encryptor,
                                                  new FileSink(outputFile.c_str())));
    } catch (const Exception& e) {
        std::cerr << "Error during encryption: " << e.what() << std::endl;
    }
}

// 解密文件
void decryptFile(const std::string& inputFile, const std::string& outputFile, const SecByteBlock& key) {
    try {
        CBC_Mode<AES>::Decryption decryptor;
        decryptor.SetKeyWithIV(key, key.size(), key);

        FileSource(inputFile.c_str(), true,
                   new StreamTransformationFilter(decryptor,
                                                  new FileSink(outputFile.c_str())));
    } catch (const Exception& e) {
        std::cerr << "Error during decryption: " << e.what() << std::endl;
    }
h