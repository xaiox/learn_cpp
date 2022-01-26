#include <iostream>
using namespace std;
#include <string>

// string µÄ¸³Öµ²Ù×÷
void test01()
{
    string str1;
    str1 = "hello world";
    cout << str1 << endl;
    string str2;
    str2 = str1;
    string str3;
    str3.assign("hello c++");
    string str4;
    str4.assign("hello c++", 2);
}

int main()
{
    test01();
    return 0;
}
