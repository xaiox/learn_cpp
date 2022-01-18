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
    // ǰ�õ������ص�ֵ���ã� ���õ������ص���ֵ
    // ����ǰ�õ���
    MyInt& operator++()
    {
        number++;
        return *this;
    }
    // ���غ��õ���
    // intΪռλ��������������ǰ�úͺ���
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