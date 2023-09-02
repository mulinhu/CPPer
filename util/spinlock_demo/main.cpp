#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
using namespace std;
class SpinLock {
public:
    SpinLock() : flag(false) {}

    void lock() {
        while (flag.exchange(true, std::memory_order_acquire)) {
            // 自旋等待锁释放
        }
    }

    void unlock() {
        flag.store(false, std::memory_order_release);
    }

private:
    std::atomic<bool> flag;
};

int counter = 0;
SpinLock spinLock;

void incrementCounter() {
    for (int i = 0; i < 100000; ++i) {
        spinLock.lock();
        counter++;
        spinLock.unlock();
    }
}

int main() {
    const int numThreads = 10;
    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(incrementCounter);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Counter: " << counter << std::endl;

    return 0;
}