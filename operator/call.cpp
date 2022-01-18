#include <iostream>
using namespace std;
#include <string>

// 函数调用运算符重载
// 仿函数(在类中重载了())
class MyPrint
{
public:
    void operator()(string test){
        cout << test << endl;
    }
};

class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1+num2;
    }
};

void test01()
{
    MyPrint my_print;
    my_print("hello world!");
}

void test02()
{
    MyAdd my_add;
    cout << my_add(100, 100) << endl;
    cout << MyAdd()(200, 200) << endl;
}
int main()
{
    test01();
    test02();
    return 0;
}