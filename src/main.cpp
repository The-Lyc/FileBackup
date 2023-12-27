#include "../include/search.h"
#include "../include/copy.h"
#include "../include/crypto.h"
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    while(1) {
        std::cout << "$main page" << std::endl;
        std::cout << "***press '1' : Display the recursive tree of the specified directory." << std::endl;
        std::cout << "***press '2' : Copy." << std::endl;
        std::cout << "***press '3' : Recover." << std::endl;
        std::cout << "***press '4' : exit." << std::endl;

        char op;
        std::cin>>op;

        switch (op) {
            case '1' : {
                std::cout<< "***input the specified directory." << std::endl;
                fs::path dir;
                std::cin >> dir;
                if (fs::exists(dir) && fs::is_directory(dir)) {
                    std::cout << "###Directory Tree for: " << dir << std::endl;
                    printTree(dir);
                } else {
                    std::cerr << "!!!Invalid directory path." << std::endl;
                }       
                break; 
            }
            case '2' : {
                fs::path sourcePath;
                fs::path destinationPath;
                std::cout << "***input the source directory." << std::endl;
                std::cin >> sourcePath;
                std::cout << "***input the destination directory." << std::endl;
                std::cin >> destinationPath;
                if(fs::exists(sourcePath) && fs::exists(destinationPath)) {
                    copy_directory(sourcePath,destinationPath,SYM_ZIP);
                }
                else {
                    std::cout<< "!!! 路径不存在 " << std::endl;
                }
                break;
            }
            case '3' : {
                fs::path sourcePath;
                fs::path destinationPath;
                std::cout << "***input the source directory." << std::endl;
                std::cin >> sourcePath;
                std::cout << "***input the destination directory." << std::endl;
                std::cin >> destinationPath;
                if(fs::exists(sourcePath) && fs::exists(destinationPath)) {
                    copy_directory(sourcePath,destinationPath,SYM_REC);
                }
                break;
            }
            case '4' : {
                return 0;
            }
        }
    }

    return 0;
}