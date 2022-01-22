#include <iostream>
using namespace std;

// 函数模板
// 不显式声明的话不能隐式转换
template <typename T>
void swap1(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

void test01()
{
    double a = 10.1;
    double b = 20.2;
    swap1(a, b);
    swap1<double>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

template<typename T>
void sort(T arr[], int len)
{
    for(int i=0; i<len; ++i)
    {
        int count = 0;
        for(int j=0; j<len-i-1; ++j)
        {
            if(arr[j]>arr[j+1]){
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                ++count;
            }
        }
        if(count == 0)
            break;
    }
    for(int i=0; i<len; ++i)
        cout << arr[i] << endl;
}

void test02()
{
    int arr1[] = {4, 2, 5, 7, 9, 1};
    int len = sizeof(arr1)/sizeof(int);
    sort(arr1, len);
    char arr2[] = "hdsfbs";
    int len2 = sizeof(arr2)/sizeof(char);
    sort(arr2, len2);
}

// 普通函数和函数模板的调用规则

int main() {
//    test01();
    test02();
    return 0;
}
