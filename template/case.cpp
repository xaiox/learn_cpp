#include <iostream>
using namespace std;
#include "myArray.hpp"

// 内置数据类型重载
void test01()
{
    MyArray<int> arr(5);
//    MyArray<int> arr2(arr);
//    MyArray<int> arr3(3);
//    arr3 = arr;
    for(int i=0; i < 5; ++i)
        arr.append(i);
    for(int i=0; i < arr.getSize(); ++i)
    {
        cout << arr[i] << endl;
    }
    cout << "arr capacity:" << arr.getCapacity() << endl;
    MyArray<int> arr2(arr);
    arr2.pop();
    for(int i=0; i < arr2.getSize(); ++i)
    {
        cout << arr2[i] << endl;
    }
    cout << "arr capacity:" << arr2.getCapacity() << endl;
}


class Person
{
public:
    string name;
    int age;
    Person(){}
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

void myPrint(MyArray<Person> &arr)
{
    for(int i=0; i<arr.getSize(); ++i)
    {
        cout << arr[i].name << "\t" << arr[i].age << endl;
    }
}
// 自定义数据类型测试
void test02()
{
    MyArray<Person> arr(10);
    Person p1("sun", 999);
    Person p2("zhang", 500);
    Person p3("li", 18);
    Person p4("liu", 30);
    arr.append(p1);
    arr.append(p2);
    arr.append(p3);
    arr.append(p4);
    myPrint(arr);
    cout << "arr capacity:" << arr.getCapacity() << endl;
    cout << "arr size:" << arr.getSize() << endl;
}

int main()
{
//    test01();
    test02();
    return 0;
}