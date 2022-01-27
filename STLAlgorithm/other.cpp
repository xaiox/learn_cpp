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
    // �������������㷨
    vector<int> v;
    // ������Ҫ��Ԫ�ظ�����������������Ҫ���ռ䣩
    v.reserve(10);
    for(int i=0;i<10;i++)
        v.push_back(i);
    // �ۼ�
    auto total = accumulate(v.begin(), v.end(), 0);

    // fill���
    vector<int> v2;
    v2.resize(10);
    fill(v.begin(), v.end(), 10);
}

void test02()
{
    // ���ü����㷨
    // set_intersection �󽻼�
    // set_union    �󲢼���Ҫ������
    // set_difference   ��
    vector<int> v1, v2;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int> v3;
    v3.resize(v1.size()>v2.size()?v2.size():v1.size());
    auto it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    // ע��Ҫʹ�÷��صĵ�����������end(), ��Ϊresize���ܶ���0
    for_each(v3.begin(), it, MyPrint());
    cout << endl;

    vector<int> v4;
    v4.resize(v1.size()+v2.size());
    auto it2 = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
    for_each(v4.begin(), it2, MyPrint());
    cout << endl;

    // v1��v2�Ĳ����v2��v1�Ĳ��ͬ��
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