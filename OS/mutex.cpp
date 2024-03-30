#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

// 定义一个共享数据
int shared_data = 0;

// 创建一个互斥锁
std::mutex mtx;

// 一个函数，用于在线程中运行，增加共享数据
void increaseSharedData() {
    // 使用互斥锁保护共享数据的操作
    mtx.lock();  // 获取锁
    shared_data++;  // 修改共享数据
    std::cout << "Shared data increased to " << shared_data << " by " << std::this_thread::get_id() << std::endl;
    mtx.unlock();  // 释放锁
}

int main() {
    // 创建多个线程，模拟多线程环境
    std::thread t1(increaseSharedData);
    std::thread t2(increaseSharedData);
    std::thread t3(increaseSharedData);

    sleep(3);

    // 等待所有线程执行完成
    std::cout << "upcoming join()" << std::endl;
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
