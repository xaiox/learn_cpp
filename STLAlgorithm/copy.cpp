#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

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
    // copy
    vector<int> v, v3;
    for(int i=0;i<10;i++){
        v.push_back(i);
        v3.push_back(i+100);
    }
    vector<int> v2;
    v2.resize(v.size());
    copy(v.begin(), v.end(), v2.begin());
    for_each(v2.begin(), v2.end(), MyPrint());
    cout << endl;

    // replace
    replace(v2.begin(), v2.end(), 1, 0);
    for_each(v2.begin(), v2.end(), MyPrint());
    cout << endl;

    // replace_if

    // swap
    swap(v, v3);
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}

int main() {
    test01();
//    test02();
//    test03();
    return 0;
}