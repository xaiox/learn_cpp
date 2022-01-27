#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>

class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << "\t" ;
    }
};
void test01()
{
    // 常用算术生成算法
    vector<int> v;
    // 声明需要的元素个数（这样容器不需要换空间）
    v.reserve(10);
    for(int i=0;i<10;i++)
        v.push_back(i);
    // 累加
    auto total = accumulate(v.begin(), v.end(), 0);

    // fill填充
    vector<int> v2;
    v2.resize(10);
    fill(v.begin(), v.end(), 10);
}

void test02()
{
    // 常用集合算法
    // set_intersection 求交集
    // set_union    求并集（要求有序）
    // set_difference   求差集
    vector<int> v1, v2;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int> v3;
    v3.resize(v1.size()>v2.size()?v2.size():v1.size());
    auto it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    // 注意要使用返回的迭代器而不是end(), 因为resize可能多了0
    for_each(v3.begin(), it, MyPrint());
    cout << endl;

    vector<int> v4;
    v4.resize(v1.size()+v2.size());
    auto it2 = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
    for_each(v4.begin(), it2, MyPrint());
    cout << endl;

    // v1和v2的差集（与v2和v1的差集不同）
    vector<int> v5;
    v5.resize(v1.size());
    auto it3 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v5.begin());
    for_each(v5.begin(), it3, MyPrint());
    cout << endl;
}

int main() {
//    test01();
    test02();
//    test03();
    return 0;
}