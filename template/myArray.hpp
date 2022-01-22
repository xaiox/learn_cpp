#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
public:
    MyArray(int capacity)
    {
        cout << "MyArray(int capacity)" << endl;
        this->capacity = capacity;
        this->size = 0;
        this->pAddress = new T[this->capacity];
    }
    MyArray(const MyArray &p)
    {
        cout << "MyArray(const MyArray &p)" << endl;
        this->capacity = p.capacity;
        this->size = p.size;
        this->pAddress = new T[p.capacity];
        // 将p的数据都拷贝过来
        for(int i=0; i<size; ++i)
        {
            pAddress[i] = p.pAddress[i];
        }
    }
    MyArray& operator=(const MyArray& p)
    {
        cout << "MyArray& operator=(const MyArray& p)" << endl;
        if(this->pAddress != nullptr){
            delete[] this->pAddress;
            pAddress = nullptr;
        }
        this->capacity = p.capacity;
        this->size = p.size;
        this->pAddress = new T[p.capacity];
        // 将p的数据都拷贝过来
        for(int i=0; i<size; ++i)
        {
            this->pAddress[i] = p.pAddress[i];
        }
        return *this;
    }

    // 尾插法
    void append(const T& val)
    {
        if(this->capacity == this->size)
            return;
        this->pAddress[this->size] = val;
        ++size;
    }
    void pop()
    {
        if(size == 0)
            return;
        --size;
    }
    T& operator[](int index)
    {
        return this->pAddress[index];
    }
    int getCapacity()
    {
        return this->capacity;
    }
    int getSize()
    {
        return this->size;
    }
    ~MyArray()
    {
        cout << "~MyArray()" << endl;
        if(pAddress != nullptr)
        {
            delete[] pAddress;
            pAddress = nullptr;
        }
    }
private:
    T *pAddress;
    int capacity;
    int size;
};