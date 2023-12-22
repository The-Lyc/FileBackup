#include<iostream>

using namespace std;

int op(char x,char y)
{
  int res=0;
  if(x>y) res=x-y;
  else  res=y-x;

  return res;
}

void printBinary(char value) {
    for (int i = 7; i >= 0; --i) {
        // 通过右移操作取得每一位的值
        char bit = (value >> i) & 1;
        std::cout << static_cast<int>(bit);  // 将 bit 转换为整数输出
    }
    cout<<endl;
}

int main()
{
  char tmp = '0';

  printBinary(tmp);

  tmp <<= 10;

  printBinary(tmp);

  string code = "11101001";
  int cnt = 0; 

  for(auto t : code) {
      cnt++;
      tmp <<= 1;
      cout<<"t:"<<t<<endl;

      if(t=='1') tmp |= 1;

      printBinary(tmp);

      // if(cnt%8 == 0) {
      //     printBinary(tmp);
      //     tmp << 10;
      // }
  }

  
  return 0;
}
