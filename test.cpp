#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// int op(char x,char y)
// {
//   int res=0;
//   if(x>y) res=x-y;
//   else  res=y-x;

//   return res;
// }

// void printBinary(char value) {
//     for (int i = 7; i >= 0; --i) {
//         // 通过右移操作取得每一位的值
//         char bit = (value >> i) & 1;
//         std::cout << static_cast<int>(bit);  // 将 bit 转换为整数输出
//     }
//     cout<<endl;
// }

// int main()
// {
//   char tmp = '0';

//   printBinary(tmp);

//   tmp <<= 10;

//   printBinary(tmp);

//   string code = "11101001";
//   int cnt = 0; 

//   for(auto t : code) {
//       cnt++;
//       tmp <<= 1;
//       cout<<"t:"<<t<<endl;

//       if(t=='1') tmp |= 1;

//       printBinary(tmp);

//       // if(cnt%8 == 0) {
//       //     printBinary(tmp);
//       //     tmp << 10;
//       // }
//   }

  
//   return 0;
// }

#include <iostream>
#include <queue> // 包含 priority_queue 头文件

// 函数接受一个引用类型的优先队列
void processPriorityQueue(std::priority_queue<int> pq) {
    // 在函数内部对优先队列进行修改
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;
}

int main() {
    // 创建一个整数型的优先队列
    std::priority_queue<int> myPriorityQueue;

    // 向优先队列中添加元素
    myPriorityQueue.push(3);
    myPriorityQueue.push(1);
    myPriorityQueue.push(4);
    myPriorityQueue.push(1);
    myPriorityQueue.push(5);

    // 调用函数，传递优先队列作为参数
    processPriorityQueue(myPriorityQueue);

    return 0;
}