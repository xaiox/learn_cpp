#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

void print01(int val)
{
    cout << val << "\t" ;
}

class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << "\t" ;
    }
};
class Transform
{
public:
    int operator()(int val)
    {
        // 搬运期间可以做一些其他的操作
        return val;
    }
};
// 常用遍历算法for_each
void test01()
{
    vector<int> v;
    for(int i=0;i<10;i++)
        v.push_back(i);
    // 普通的函数或仿函数
//    for_each(v.begin(), v.end(), print01);
//    cout << endl;
//    for_each(v.begin(), v.end(), MyPrint());

    // 遍历算法transform
    vector<int> v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), Transform());
    for_each(v2.begin(), v2.end(), MyPrint());
}

// 常用查找算法
class Person
{
public:
    string name;
    int age;
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    bool operator==(const Person &p2)
    {
        if(this->name==p2.name && this->age==p2.age)
            return true;
        return false;
    }
};
void test02()
{
    vector<int> v;
    for(int i=0;i<10;i++)
        v.push_back(i);
    auto it = find(v.begin(), v.end(), 50);
    if(it==v.end()) cout << "No!" << endl;
    else cout << "Yes!" << endl;

    vector<Person> v2;
    Person p1("a", 18);
    Person p2("b", 20);
    Person p3("c", 30);
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    auto it2 = find(v2.begin(), v2.end(), p2);
    if(it2==v2.end()) cout << "No!" << endl;
    else cout << "Yes!" << endl;
}
// find_if  根据条件查找元素
// adjacent_if  查找相邻元素
// binary_search    二分查找（返回bool 非迭代器）(只能用在有序的序列)
// count    统计元素（统计自定义数据类型需要在类型中重载==）
// count_if 按照条件统计元素个数
int main() {
    test01();
    test02();
    return 0;
}
