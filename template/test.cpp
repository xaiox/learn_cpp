#include <iostream>
using namespace std;

// 函数模板
void myPrint(int a, int b)
{
    cout << "func" << endl;
}
template<typename T>
void myPrint(T a, T b)
{
    cout << "template func" << endl;
}
// 模板可以进行函数重载
template<typename T>
void myPrint(T a, T b, T c)
{
    cout << "template func re" << endl;
}

void test01()
{
    // 普通函数和模板函数优先调用普通函数
    myPrint(3, 4);
    // 通过带<>可以强制调用模板
    myPrint<>(3, 4);
    // 重载
    myPrint(3, 4, 5);
    // 如果模板可以产生更好的匹配（普通函数需要隐式类型转换），调用模板
    myPrint('a', 'b');
}

// 模板的局限性

class Person
{
public:
    int age;
    string name;
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
//    bool operator==(Person &p2)
//    {
//        if(p2.age == this->age && p2.name == this->name)
//            return true;
//        else
//            return false;
//    }
};

template<class T>
bool compare(T &a, T &b)
{
    if(a==b) return true;
    else return false;
}
// 对特定的数据类型具体化
template<> bool compare(Person &p1, Person &p2)
{
    if(p2.age == p1.age && p2.name == p1.name)
        return true;
    else
        return false;
}
void test02()
{
    Person p1("Tom", 18);
    Person p2("Tom", 18);
    compare(p1, p2);
}
int main()
{
//    test01();
    test02();
    return 0;
}