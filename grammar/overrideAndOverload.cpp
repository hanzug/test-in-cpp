#include <iostream>
using namespace std;

// 基类
class Animal {
public:
    // 虚函数，允许在派生类中被重写
    virtual void speak() {
        cout << "Some animal makes a sound." << endl;
    }
};

// 派生类
class Dog : public Animal {
public:
    // 重写基类中的speak函数
    void speak() override {
        cout << "Dog barks." << endl;
    }
};

// 函数重载的例子
class DisplayOverload {
public:
    void display(int i) {
        cout << "Displaying int: " << i << endl;
    }
    void display(double d) {
        cout << "Displaying double: " << d << endl;
    }
    void display(string s) {
        cout << "Displaying string: " << s << endl;
    }
};

int main() {
    // 方法重写的演示
    Animal* animal = new Dog(); // 基类指针指向派生类对象
    animal->speak(); // 调用的是Dog类中重写的speak方法

    // 函数重载的演示
    DisplayOverload obj;
    obj.display(10);
    obj.display(3.14);
    obj.display("Hello, World!");

    delete animal; // 释放内存
    return 0;
}
