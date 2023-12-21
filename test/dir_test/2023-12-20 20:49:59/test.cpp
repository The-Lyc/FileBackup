#include <iostream>
#include <ctime>

int main() {
    // 输入的时间戳
    std::time_t timestamp = 1703062565;

    // 转换为 struct tm 结构体
    struct tm* timeinfo = std::gmtime(&timestamp);

    // 将 struct tm 格式化为字符串
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);

    std::cout << "Converted time: " << buffer << std::endl;

    return 0;
}