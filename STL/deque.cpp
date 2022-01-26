#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

void myPrint(const deque<int> &d)
{
    for(deque<int>::const_iterator it = d.begin();it!=d.end();it++)
    {
        cout << *it << endl;
    }
}
void test01()
{
    // deque的构造
    deque<int> d;
    for(int i=0;i<5;i++) {
        d.push_back(i);
        d.push_front(10-i);
    }
    d.pop_back();
    d.pop_front();
//    deque<int>d2(d.begin(), d.end());
//    deque<int>d3(10, 100);
//    deque<int>d4(d3);
//    myPrint(d);
    deque<int> d2;
    d2.insert(d2.begin(), d.begin(), d.end());
    d2.erase(d2.begin()+1);
    // 默认从小到大 升序
    sort(d2.begin(), d2.end());
    myPrint(d2);
//    d2.clear();
}
void test02()
{
    deque<int> d;
    d.push_front(10);
    d.insert(d.begin(), 1000);
    d.insert(d.begin(), 8, 10);
    myPrint(d);
}

int main()
{
    test01();
//    test02();
    return 0;
}