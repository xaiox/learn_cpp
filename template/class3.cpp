#include <iostream>
using namespace std;

template<class T1, class T2>
class Person;

// 全局函数类外实现(较复杂) 最好用类内实现
template<class T1, class T2>
void show(Person<T1, T2>p)
{
    cout << p.age << endl;
    cout << p.name << endl;
}

template<class T1, class T2>
class Person
{
//    friend void show(Person<T1, T2>p)
//    {
//        cout << p.age << endl;
//        cout << p.name << endl;
//    }
    friend void show<>(Person<T1, T2>p);
public:
    Person(T1 name, T2 age)
    {
        this->name = name;
        this->age = age;
    }
private:
    T1 name;
    T2 age;
};


void test01()
{
    Person<string, int> p("sa", 18);
    show(p);
}
int main()
{
    test01();
    return 0;
}