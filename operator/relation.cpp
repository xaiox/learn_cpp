#include <iostream>
using namespace std;
#include <string>

// ��ϵ���������
class Person
{
public:
    int age;
    string name;
    Person(string name, int age){
        this->age = age;
        this->name = name;
    }
    bool operator==(Person &p){
        if(this->age==p.age && this->name==p.name)
            return true;
        return false;
    }
};

void test01(){
    Person p1("Tom", 18);
    Person p2("Tom", 18);
    if(p1==p2){
        cout << "���" << endl;
    }
    else{
        cout << "�����" << endl;
    }
}

int main()
{
    test01();
    return 0;
}