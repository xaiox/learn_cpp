#include <iostream>
using namespace std;
#include <string>

// 运算符重载
class Person
{
public:
    int a, b;
    Person(){
        a = 10;
        b = 10;
    }
    // 成员函数运算符重载
    Person operator+(Person& p)
    {
        Person temp;
        temp.a = this->a + p.a;
        temp.b = this->b + p.b;
        return temp;
    }
};

// 全局函数运算符重载
Person operator+(Person& p1, int number)
{
    Person temp;
    temp.a = p1.a + number;
    temp.b = p1.b + number;
    return temp;
}

void test01(){
    Person p1, p2;
    Person p3 = p1 + 20;
    cout << p3.a;
}
int main() {
    test01();
    return 0;
}
