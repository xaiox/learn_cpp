#include <iostream>
using namespace std;
#include <string>

// 左移运算符重载
class Person
{
    friend ostream& operator<<(ostream &cout, Person &p);
public:
    Person(int a, int b){
        this->a = a;
        this->b = b;
    }
    // 通常不会用成员函数来重载左移运算符，无法实现cout在左边
private:
    int a, b;
};

ostream& operator<<(ostream &out, Person &p)
{
    cout << "p.a = " << p.a << "\np.b = " << p.b;
    // cout 有链式编程，所以要返回cout 的引用
    return out;
}

int main()
{
    Person p(10, 10);
    cout << p << endl;
    return 0;
}