#include <iostream>
using namespace std;
#include <string>

// �������������
class Person
{
    friend ostream& operator<<(ostream &cout, Person &p);
public:
    Person(int a, int b){
        this->a = a;
        this->b = b;
    }
    // ͨ�������ó�Ա����������������������޷�ʵ��cout�����
private:
    int a, b;
};

ostream& operator<<(ostream &out, Person &p)
{
    cout << "p.a = " << p.a << "\np.b = " << p.b;
    // cout ����ʽ��̣�����Ҫ����cout ������
    return out;
}

int main()
{
    Person p(10, 10);
    cout << p << endl;
    return 0;
}