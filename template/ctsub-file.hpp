#pragma once
#include <iostream>
using namespace std;

// 类模板的分文件编写
template<class T1, class T2>
class Person
{
public:
    T1 name;
    T2 age;
    Person(T1 name, T2 age);
    void show();
};
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->name = name;
    this->age = age;
}
template<class T1, class T2>
void Person<T1, T2>::show() {
    cout << "show" << endl;
}