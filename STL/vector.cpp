#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void vectorPrint(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin();it!=v.end();it++)
        cout << *it << endl;
}
void test01()
{
    // vector容器的构造
    vector<int> v1;
    v1.push_back(10);
    vector<int> v2(v1.begin(), v1.end());
    vector<int> v3(10, 100);
    vector<int> v4(v3);
    vectorPrint(v4);
}

// 使用swap()
void test02()
{
    vector<int> v1;
    for(int i=0;i < 10000; i++)
    {
        v1.push_back(i);
    }
    cout << v1.capacity() << endl;
    cout << v1.size() << endl;
    v1.resize(3);
    cout << v1.capacity() << endl;
    // 利用swap收缩容量
    vector<int>(v1).swap(v1);
    cout << v1.capacity() << endl;
    cout << v1.size() << endl;
}
void test03()
{
    vector<int> v;
    // 预留空间，不用动态扩展
    v.reserve(100000);
    int count = 0;
    int capacity = v.capacity();
    for(int i=0;i < 100000; i++)
    {
        v.push_back(i);
        if(capacity != v.capacity())
        {
            count ++;
            capacity = v.capacity();
        }
    }
    cout << v.capacity() << endl;
    cout << count << endl;
}
int main()
{
//    test02();
    test03();
    return 0;
}