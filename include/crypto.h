#ifndef _CRYPTO_
#define _CRYPTO_

#include <string>
#include <iomanip>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include "../cryptopp/aes.h"
#include "../cryptopp/modes.h"
#include "../cryptopp/files.h"
#include "../cryptopp/filters.h"
#include "../cryptopp/osrng.h"
#include "../cryptopp/pwdbased.h"

using namespace CryptoPP;

// 获取用户输入的密码
std::string getUserPassword();
// 生成密钥
SecByteBlock generateKey(const std::string& password);
// 加密文件
void encryptFile(const std::string& inputFile, const std::string& outputFile, const SecByteBlock& key);
// 解密文件
void decryptFile(const std::string& inputFile, const std::string& outputFile, const SecByteBlock& key);

#endif