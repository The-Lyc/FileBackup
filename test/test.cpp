#include <algorithm>
#include <cstdio>
#include <fcntl.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>


void printBinary(char value) {
    for (int i = 7; i >= 0; --i) {
        // 通过右移操作取得每一位的值
        char bit = (value >> i) & 1;
        std::cout << static_cast<int>(bit);  // 将 bit 转换为整数输出
    }
    std::cout<<std::endl;
}
// 定义哈夫曼树的节点
struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char _data, int _frequency) : data(_data), frequency(_frequency), left(nullptr), right(nullptr) {}
};

// 用于比较两个节点的函数对象
struct CompareNodes {
    bool operator()(HuffmanNode* lhs, HuffmanNode* rhs) {
        return lhs->frequency > rhs->frequency;
    }
};

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
HuffmanNode* buildHuffmanTree(const std::string& input) {
    // 统计字符频率
    std::map<char, int> frequencyMap;
    for (char ch : input) {
        frequencyMap[ch]++;
    }

    // 使用优先队列构建哈夫曼树
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNodes> pq;
    for (const auto& pair : frequencyMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

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


void recoverFromCode(std::string sourcePath, HuffmanNode* root , std::string destPath,int len) {
    std::ifstream sourceFile(sourcePath.c_str());
    std::fstream destFile(destPath.c_str(),std::ios::out | std::ios::trunc);

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

int main()
{
    std::string sourcePath = "test" ;
    std::string tempPath =  "/home/lyc/workspace/tmp/huffman.txt" ;
    std::string destPath = "huffman.txt" ;

    std::ifstream sourceFile(sourcePath);
    std::fstream tempFile(tempPath,std::ios::out | std::ios::trunc);
    // 从输入文件读取内容并写入输出文件

    std::string sourceStr;

    char ch;
    while (sourceFile.get(ch)) {
        sourceStr += ch;   
    }
    HuffmanNode* root = buildHuffmanTree(sourceStr);

    std::string code;
    std::map<char, std::string> huffmanCodeMap;
    generateHuffmanCode(root, code, huffmanCodeMap);

    // for(auto ans : huffmanCodeMap) {
    //     std::cout<<ans.first<<":"<<ans.second<<std::endl;
    // }

    int cnt = 0;
    char tmp = 0;

    tmp &= 0 ;

    // std::cout<<sourceStr<<std::endl;

    for( auto ch : sourceStr) {
        code = huffmanCodeMap[ch];
        // std::cout<<ch<<"->"<<code<<std::endl;
        for(auto t : code) {
            // std::cout<<t<<std::endl;
            cnt++;
            tmp <<= 1;
            if(t=='1') tmp |= 1;

            if(cnt%8 == 0) {
                tempFile << tmp;
                tmp &= 0;
            }
        }
    }

    for(int i=(cnt%8);i<8;i++) {
        tmp<<=1;
    }
    tempFile << tmp;

    sourceFile.close();
    tempFile.close();

    recoverFromCode(tempPath,root,destPath,cnt);

}
