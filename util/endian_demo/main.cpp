#include <iostream>

union EndianChecker {
    int value;
    char bytes[sizeof(int)];
};
bool is_smallEndian(){
    EndianChecker checker;
    checker.value = 1;
    return checker.bytes[0] == 1;
}
int main() {
    bool flag = is_smallEndian();
    

    if (flag) {
        std::cout << "This machine is using little-endian storage." << std::endl;
    } else {
        std::cout << "This machine is using big-endian storage." << std::endl;
    }

    return 0;
}