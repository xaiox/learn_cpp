#include <iostream>
using namespace std;
#include "ctsub-file.hpp"

// 类模板

// 类模板对象做函数参数
//template<class T1, class T2>
//class Person
//{
//public:
//    T1 name;
//    T2 age;
//    Person(T1 name, T2 age)
//    {
//        this->name = name;
//        this->age = age;
//    }
//
//};
//// 指定传入类型
//void test01(Person<string, int>&p)
//{
//    cout << p.age << "\t" << p.name << endl;
//}
//// 参数模板化
//template<class T1, class T2>
//void test02(Person<T1, T2>&p)
//{
//    cout << p.age << "\t" << p.name << endl;
//    // 查看T的类型
////    cout << "T1:" << typeid(T1).name() << endl;
////    cout << "T2:" << typeid(T2).name() << endl;
//}
//// 整个类模板化
//template<class T>
//void test03(T &p)
//{
//    cout << p.age << "\t" << p.name << endl;
//    cout << "T:" << typeid(T).name() << endl;
//}
//
//
//// 类模板与继承
//template<class T>
//class Base
//{
//public:
//    T a;
//};
//template<class T1, class T2>
//class Son:public Base<T1>
//{
//public:
//    T2 b;
//};

//void test01()
//{
//    Son<int, char> son1;
//}

void test04()
{
    Person<string, int> p("li", 18);
    p.show();
}
int main()
{
//    Person<string, int> p("li", 18);
//    Person<string, int> p2("zhang", 20);
//    Person<string, int> p3("san", 25);
//    test01(p);
//    test02(p2);
//    test03(p3);
    test04();
    return 0;
}