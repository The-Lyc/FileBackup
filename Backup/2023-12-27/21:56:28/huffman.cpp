#include "../include/huffman.h"
#include <unistd.h>

void printBinary(char value) {
    for (int i = 7; i >= 0; --i) {
        // 通过右移操作取得每一位的值
        char bit = (value >> i) & 1;
        std::cout << static_cast<int>(bit);  // 将 bit 转换为整数输出
    }
    std::cout<<std::endl;
}

// 生成哈夫曼编码
void generateHuffmanCode(HuffmanNode* root, std::string code, std::map<char, std::string>& huffmanCodeMap) {
    if (root == nullptr) {
        return;
    }

    if (root->data != '\0') {
        huffmanCodeMap[root->data] = code;
    }

    generateHuffmanCode(root->left, code + "0", huffmanCodeMap);
    generateHuffmanCode(root->right, code + "1", huffmanCodeMap);

}

// 构建哈夫曼树
HuffmanNode* buildHuffmanTree(std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNodes> pq) {
    // // 统计字符频率
    // std::map<char, int> frequencyMap;
    // for (char ch : input) {
    //     frequencyMap[ch]++;
    // }

    // // 使用优先队列构建哈夫曼树
    // std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNodes> pq;
    // for (const auto& pair : frequencyMap) {
    //     pq.push(new HuffmanNode(pair.first, pair.second));
    // }

    // 构建哈夫曼树
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();

        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* newNode = new HuffmanNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // 返回根节点
    return pq.top();
}

//恢复函数：每个被压缩的文件，文件第一行必须是k（该文件有多少种字符，即下面紧接着有多少行<字符，次数>和len（源文件压缩后的编码长度））
void recoverFromCode(std::string sourcePath,  std::string destPath) {
    HuffmanNode* root;
    long long k;
    long long len;
    std::ifstream sourceFile(sourcePath.c_str());
    std::fstream destFile(destPath.c_str(),std::ios::out | std::ios::trunc);

    sourceFile >> k >> len;

    // 统计字符频率
    std::map<char, int> frequencyMap;
    char ch;
    int f;
    while(k--) {
        sourceFile.get();
        sourceFile.get(ch);
        sourceFile.get();
        sourceFile >> f;
        frequencyMap[ch]+=f;
    }

    sourceFile.get();

    // 使用优先队列构建哈夫曼树
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNodes> pq;
    for (const auto& pair : frequencyMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    root = buildHuffmanTree(pq);

    HuffmanNode* cur = root;
    int cnt = 0;
    char ans;
    while (sourceFile.get(ans)) {
        // std::cout<<ans<<std::endl;

        std::string tmp;
        for(int i=0;i<8;i++) {
            cnt++;
            if(cnt>len) break;
            char c = ans&1;
            // printBinary(c);
            tmp+=c+'0';
            ans>>=1;
        }
        std::reverse(tmp.begin(),tmp.end());

        // std::cout<<tmp<<std::endl;

        for(auto buf : tmp) {
            if(cur->data != '\0' ) {
                destFile << cur->data;
                cur = root;
            }
            else {
                if(buf == '0') {
                    cur = cur->left;
                }
                else {
                    cur = cur->right;
                }

                if(cur->data != '\0' ) {
                    destFile << cur->data;
                    cur = root;
                }
            }
        }
        
    }

    sourceFile.close();
    destFile.close();
}

void zipToCode(std::string sourcePath, std::string destPath) {
    char * buf;

    std::string tempPath = destPath;
    // tempPath = getcwd(buf,1024);
    // std::cout<<tempPath<<std::endl;
    // tempPath = "/home/lyc/cpp_ws/file_backup/Test/tmp/huffman.txt";

    std::ifstream sourceFile(sourcePath);
    std::fstream tempFile(tempPath,std::ios::out | std::ios::trunc);
    // // 从输入文件读取内容并写入输出文件

    std::string sourceStr ;
    // // 统计字符频率
    std::map<char, int> frequencyMap;
    char ch;
    while (sourceFile.get(ch)) {
        sourceStr += ch;   
        frequencyMap[ch]++;
    }

    // std::cout << sourceStr.size() << std::endl;

    // 使用优先队列构建哈夫曼树
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNodes> pq;
    for (const auto& pair : frequencyMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // std::cout << pq.size() << std::endl;
    HuffmanNode* root = buildHuffmanTree(pq);

    std::string code;
    std::map<char, std::string> huffmanCodeMap;
    generateHuffmanCode(root, code, huffmanCodeMap);

    //处理压缩后的哈夫曼编码
    int cnt = 0;
    char tmp = 0;

    tmp &= 0 ;
    std::string zipcode;

    for( auto ch : sourceStr) {
        code = huffmanCodeMap[ch];
        for(auto t : code) {
            cnt++;
            tmp <<= 1;
            if(t=='1') tmp |= 1;

            if(cnt%8 == 0) {
                zipcode += tmp;
                tmp &= 0;
            }
        }
    }

    for(int i=(cnt%8);i<8;i++) {
        tmp<<=1;
    }
    zipcode += tmp;


    //处理文件头（存重建哈夫曼树的必要信息）
    tempFile.seekg(0,std::ios::beg);
    int k = frequencyMap.size();
    tempFile << k << " " << cnt << " ";
    for(auto t : frequencyMap) {
        tempFile << t.first << " " << t.second << " ";
        // std::cout << t.first << " " << t.second << " ";
    }

    tempFile << zipcode;

    sourceFile.close();
    tempFile.close();    

}

