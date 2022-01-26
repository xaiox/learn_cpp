#include <iostream>
using namespace std;
#include <set>
#include <algorithm>

// set和multiset
// set中没有重复的元素，所有的元素会默认排序
// set不能resize
void myPrint(const set<int> &s)
{
    for(set<int>::const_iterator it=s.begin();it!=s.end();it++)
    {
        cout << *it << endl;
    }
}

void test01()
{
    set<int> s;
    s.insert(10);
    s.insert(40);
    s.insert(30);
    s.insert(30);
    myPrint(s);
}

void test02()
{
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    pair<set<int>::iterator, bool> ret2 = s.insert(10);
    cout << ret2.second << endl;
    multiset<int> m;
    // multiset可以重复插数据
}

// pair对组
void test03()
{
    pair<string, int> p("Tom", 20);
    pair<string, int> p2 = make_pair("Jerry", 30);
    cout << p.first << "\t" << p.second << endl;
    cout << p2.first << "\t" << p2.second << endl;
}

class Person
{
public:
    string name;
    int age;
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
};

class MyCompare
{
public:
    // 这里必须加const
    bool operator()(const Person &p1, const Person &p2){
        return p1.age > p2.age;
    }
};
void myPrint(const set<Person, MyCompare> &s)
{
    for(set<Person, MyCompare>::const_iterator it=s.begin();it!=s.end();it++)
    {
        cout << it->name << "\t" << it->age << endl;
    }
}
// set容器排序
void test04()
{
    // 用仿函数指定排序规则
    set<Person, MyCompare> s;
    Person p1("li", 20);
    Person p2("zhang", 30);

    s.insert(p1);
    s.insert(p2);
    myPrint(s);
}
int main()
{
//    test01();
//    test02();
//    test03();
    test04();
    return 0;
}