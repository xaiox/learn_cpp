#include <iostream>
using namespace std;
#include <list>
#include <deque>

void myPrint(const list<int> &l)
{
    for(list<int>::const_iterator it = l.begin(); it!=l.end(); it++)
    {
        cout << *it << endl;
    }
}

bool myCompare(int a, int b)
{
    // 降序
    return a > b;
}

void test01()
{
    list<int> l;
    l.push_back(10);
    l.push_back(20);
    list<int> l2(10, 10);
    l.swap(l2);
    l.reverse();
    myPrint(l2);
    // 不支持随机访问迭代器的容器不能用标准算法，可以用容器内部实现的算法
    l2.sort(myCompare);
    myPrint(l2);
}

class Person
{
public:
    // 优先按照年龄升序，相同按升高降序
    string name;
    int age;
    int height;
    Person(string name, int age, int height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }
};

void myPrint(const list<Person> &l)
{
    for(list<Person>::const_iterator it = l.begin(); it!=l.end(); it++)
    {
        cout << it->name <<  "\t " << it->age << "\t" << it->height << endl;
    }
}

bool mySort(Person &p1, Person &p2){
    if(p1.age > p2.age)
        return false;
    else if(p1.age < p2.age)
        return true;
    else{
        return p1.height > p2.height;
    }
}

void test02()
{
    list<Person> l;
    Person p1("a", 35, 175);
    Person p2("b", 45, 180);
    Person p3("c", 40, 170);
    Person p4("d", 25, 190);
    Person p5("e", 35, 160);
    Person p6("f", 35, 200);

    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);

    myPrint(l);
    l.sort(mySort);
    myPrint(l);
}

int main()
{
//    test01();
    test02();
    return 0;
}