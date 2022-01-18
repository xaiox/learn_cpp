#include <iostream>
using namespace std;
#include <string>

class MyInt
{
    friend ostream& operator<<(ostream &out, const MyInt &my_int);
public:
    MyInt(){
        number = 0;
    }
    // 前置递增返回的值引用， 后置递增返回的是值
    // 重载前置递增
    MyInt& operator++()
    {
        number++;
        return *this;
    }
    // 重载后置递增
    // int为占位参数，可以区分前置和后置
    MyInt operator++(int)
    {
        MyInt temp = *this;
        number++;
        return temp;
    }
private:
    int number;
};

ostream& operator<<(ostream &out, const MyInt &my_int){
    cout << my_int.number;
    return out;
}

void test01()
{
    MyInt my_int;
    cout << ++my_int << endl;
    cout << my_int++ << endl;
    cout << my_int << endl;
}

int main()
{
    test01();
    return 0;
}