#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

// ��������
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

// ����bool���͵ķº�����Ϊν��
// operator()����һ��������ΪһԪν�ʣ�--��---��Ԫ--
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

// �ڽ���������
void test03()
{
    // �����º���
    // ȡ���ķº���
    negate<int> n;
    // �ӷ��ķº���
    plus<int> p;
//    cout << n(50) << endl;
//    cout << p(10, 20) << endl;

    // ��ϵ�º���
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    // ����
    sort(v.begin(), v.end(), greater<>());
//    for(auto it : v)
//        cout << it << endl;

    // �߼��º���
    logical_not<bool> l;
    vector<bool> v1;
    v1.push_back(true);
    v1.push_back(true);
    v1.push_back(true);
    vector<bool> v2;
    v2.resize(v1.size());
    // ������ȡ��
    transform(v1.begin(), v1.end(), v2.begin(), l);
}
int main()
{
//    test01();
//    test02();
    test03();
    return 0;
}