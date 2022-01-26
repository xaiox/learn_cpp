#include <iostream>
using namespace std;
#include <map>

void printMap(map<int, int> &m)
{
    for(map<int, int>::iterator it = m.begin();it!=m.end();it++)
    {
        cout << "key: " << it->first << endl;
        cout << "value: " << it->second << endl;
    }
}

void test01()
{
    map<int, int> m;
    // Ĭ�ϰ���key����
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int> (3, 30));
    m.insert(pair<int, int> (2, 20));
    m.insert(make_pair(4, 15));
    printMap(m);

    map<int, int> m2(m);

}

class MyCompare
{
public:
    bool operator()(int a, int b)
    {
        // ����
        return a > b;
    }
};
void test02()
{
    // �����set���ƣ������÷º����Զ����������
    map<int, int, MyCompare> m;
    m.insert(make_pair(2, 20));
    m.insert(make_pair(1, 10));
    m.insert(make_pair(3, 30));

    for(map<int, int, MyCompare>::iterator it = m.begin(); it!=m.end(); it++)
    {
        cout << "key: " << it->first << "\t";
        cout << "value: " << it->second << "\t";
    }
}

int main()
{
//    test01();
    test02();
//    test03();
//    test04();
    return 0;
}