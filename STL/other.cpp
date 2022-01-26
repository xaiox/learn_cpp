#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

// 函数对象
class MyPrint
{
public:
    int operator()(string test)
    {
        cout << test << endl;
    }
};
void doPrint(MyPrint &p, string test)
{
    p(test);
}
void test01()
{
    MyPrint myPrint;
    doPrint(myPrint, "test");
}

// 返回bool类型的仿函数称为谓词
// operator()接受一个参数称为一元谓词，--二---二元--
class Compare
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};
void test02()
{
    vector<int> v;
    for(int i=0; i<10; i++)
        v.push_back(i);
    auto it = find_if(v.begin(), v.end(), Compare());
    if(it == v.end())
        cout << "No" << endl;
    else
        cout << "Yes:" << *it << endl;
}

// 内建函数对象
void test03()
{
    // 算术仿函数
    // 取反的仿函数
    negate<int> n;
    // 加法的仿函数
    plus<int> p;
//    cout << n(50) << endl;
//    cout << p(10, 20) << endl;

    // 关系仿函数
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    // 降序
    sort(v.begin(), v.end(), greater<>());
//    for(auto it : v)
//        cout << it << endl;

    // 逻辑仿函数
    logical_not<bool> l;
    vector<bool> v1;
    v1.push_back(true);
    v1.push_back(true);
    v1.push_back(true);
    vector<bool> v2;
    v2.resize(v1.size());
    // 搬运且取反
    transform(v1.begin(), v1.end(), v2.begin(), l);
}
int main()
{
//    test01();
//    test02();
    test03();
    return 0;
}