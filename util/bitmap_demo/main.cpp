#include <iostream>
#include <vector>
using namespace std;
class Bitmap {
private:
    std::vector<uint8_t> data; // 位图数据存储
    uint64_t size; // 位图大小（位数）

public:
    Bitmap(uint64_t bitmapSize) {
        size = bitmapSize;
        data.resize((size + 7) / 8, 0); // 位图数据初始化为0
    }

    void set(uint64_t index) {
        if (index >= size) {
            std::cout << "Index out of range." << std::endl;
            return;
        }
        uint64_t byteIndex = index / 8;
        uint8_t bitOffset = index % 8;
        data[byteIndex] |= (1 << bitOffset);
    }

    bool test(uint64_t index) {
        if (index >= size) {
            std::cout << "Index out of range." << std::endl;
            return false;
        }
        uint64_t byteIndex = index / 8;
        uint8_t bitOffset = index % 8;
        return (data[byteIndex] & (1 << bitOffset)) != 0;
    }
};
int main(){
    const uint64_t bitmapSize = 28; // 位图大小

    Bitmap bitmap(bitmapSize); // 创建位图

    // 设置一些位
    bitmap.set(0);
    bitmap.set(5);
    bitmap.set(10);
    bitmap.set(15);
    bitmap.set(18);

    // 测试位状态
    for (uint64_t i = 0; i < bitmapSize; i++) {
        std::cout << "Bit " << i << ": " << bitmap.test(i) << std::endl;
    }

    return 0;

}