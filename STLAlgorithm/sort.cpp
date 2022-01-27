#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <ctime>

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
    vector<int> v;
    for(int i=0;i<10;i++)
        v.push_back(rand()%10+1);
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
    sort(v.begin(), v.end(), greater<>());
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
    // random_shuffle打乱(用随机数种子可以真打乱)
    srand((unsigned int) time(nullptr));
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}

void test02()
{
    // merge(将两个有序序列合并为一个有序序列)
    vector<int> v1, v2;
    for(int i=0;i<5;i++)
    {
        v1.push_back(i);
        v2.push_back(i+3);
    }
    vector<int> v3;
    v3.resize(v1.size()+v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for_each(v3.begin(), v3.end(), MyPrint());
}

void test03()
{
    // reverse
    vector<int> v;
    for(int i=0;i<10;i++)
        v.push_back(i);
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}
int main() {
//    test01();
//    test02();
    test03();
    return 0;
}
