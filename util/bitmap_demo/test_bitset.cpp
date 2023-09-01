#include <iostream>
#include <bitset>

int main() {
    // 创建一个位图，表示 8 个标志位
    std::bitset<8> bitmap;

    // 设置第 2 位和第 5 位为 1
    bitmap.set(2);
    bitmap.set(5);

    // 输出位图的值
    std::cout << "Bitmap: " << bitmap << std::endl;

    // 获取第 3 位的值
    bool bit3 = bitmap.test(3);
    std::cout << "Bit 3: " << bit3 << std::endl;

    // 清除第 5 位
    bitmap.reset(5);

    // 输出位图的值
    std::cout << "Bitmap: " << bitmap << std::endl;

    // 获取位图的大小（位数）
    size_t size = bitmap.size();
    std::cout << "Bitmap size: " << size << std::endl;

    return 0;
}