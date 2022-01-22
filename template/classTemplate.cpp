#include <iostream>
using namespace std;

// 类模板
// 不能进行自动类型推导
// 可以默认类型
// 类模板中的成员函数在调用时才会创建
template<class NameType = string, class AgeType = int>
class Person
{
public:
    NameType name;
    AgeType age;
    Person(NameType name, AgeType age)
    {
        this->name = name;
        this->age = age;
    }
    void show()
    {
        cout << "show" << endl;
    }
};

void test01()
{
    Person<string, int> p1("孙悟空", 500);
    Person<> p2("猪八戒", 1000);
}
int main()
{
    return 0;
}