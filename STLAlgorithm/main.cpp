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
        // �����ڼ������һЩ�����Ĳ���
        return val;
    }
};
// ���ñ����㷨for_each
void test01()
{
    vector<int> v;
    for(int i=0;i<10;i++)
        v.push_back(i);
    // ��ͨ�ĺ�����º���
//    for_each(v.begin(), v.end(), print01);
//    cout << endl;
//    for_each(v.begin(), v.end(), MyPrint());

    // �����㷨transform
    vector<int> v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), Transform());
    for_each(v2.begin(), v2.end(), MyPrint());
}

// ���ò����㷨
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
// find_if  ������������Ԫ��
// adjacent_if  ��������Ԫ��
// binary_search    ���ֲ��ң�����bool �ǵ�������(ֻ���������������)
// count    ͳ��Ԫ�أ�ͳ���Զ�������������Ҫ������������==��
// count_if ��������ͳ��Ԫ�ظ���
int main() {
    test01();
    test02();
    return 0;
}
