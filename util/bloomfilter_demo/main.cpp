#include <iostream>
#include <bitset>
#include <functional>

class BloomFilter {
private:
    std::bitset<1000000> bitmap; // 位图
    std::hash<std::string> hashFunction; // 哈希函数

public:
    void add(const std::string& element) {
        size_t hash = hashFunction(element); // 计算哈希值
        bitmap[hash % 1000000] = true; // 将对应位置设置为1
    }

    bool lookup(const std::string& element) {
        size_t hash = hashFunction(element); // 计算哈希值
        return bitmap[hash % 1000000]; // 返回对应位置的值
    }
};

int main() {
    BloomFilter filter;

    // 插入元素
    filter.add("element1");
    filter.add("element2");
    filter.add("element3");

    // 检查元素是否存在
    bool exists1 = filter.lookup("element1");
    bool exists2 = filter.lookup("element4");

    // 输出结果
    std::cout << "Element 1 exists: " << exists1 << std::endl;
    std::cout << "Element 4 exists: " << exists2 << std::endl;

    return 0;
}