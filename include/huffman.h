#ifndef HUFFMAN_H_
#define HUFFMAN_H_

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
#include <iostream>

void printBinary(char value);

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
void generateHuffmanCode(HuffmanNode* root, std::string code, std::map<char, std::string>& huffmanCodeMap);

// 构建哈夫曼树
HuffmanNode* buildHuffmanTree(std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNodes> pq);

// 从哈夫曼编码恢复文件
void recoverFromCode(std::string sourcePath,  std::string destPath);

// 利用哈夫曼算法压缩文件
void zipToCode(std::string sourcePath, std::string destPath);

#endif