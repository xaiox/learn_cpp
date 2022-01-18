#include <iostream>
using namespace std;
#include <string>

// 赋值运算符的重载
class Person
{
public:
    int *age;
    Person(int age)
    {
        this->age = new int(age);
    }
    Person(const Person &p){
        this->age = new int(*p.age);
    }
    ~Person(){
        delete this->age;
    }
    Person& operator=(Person &p){
        if(age != nullptr){
            delete age;
        }
        this->age = new int(*p.age);
        return *this;
    }
};

ostream& operator<<(ostream &out, Person &p)
{
    cout << *p.age;
    return out;
}

void test01()
{
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p2 = p1 = p3;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
}

int main()
{
    test01();
    return 0;
}