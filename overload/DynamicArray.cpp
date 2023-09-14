#include "DynamicArray.h"
#include<Windows.h>
#include <iostream>
using namespace std;
DynamicArray::DynamicArray() :ptr(nullptr), size(0)
{}
DynamicArray::DynamicArray(int S)
{
    cout << "Construct by 1 param\n";
    size = S;
    ptr = new int[S];
}

DynamicArray::DynamicArray(const DynamicArray& a)// copy constructor
{
    cout << "Copy construct\n";
    size = a.size;
    ptr = new int[size];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = a.ptr[i];
    }
}
DynamicArray::~DynamicArray()
{
    cout << "Destruct\n";
    if (ptr != 0)
    {
        delete[] ptr;
    }
    Sleep(1000);
}
void DynamicArray::Input()
{
    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % 20;
    }
}
void DynamicArray::Output() const
{
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << "\t";
    }
    cout << "\n---------------------------------\n";
}
int* DynamicArray::GetPointer() const
{
    return ptr;
}
int DynamicArray::GetSize()const
{
    return size;
}
DynamicArray DynamicArray:: operator+(int b)
{
    DynamicArray rez;
    rez.size = this->size + b;
    rez.ptr = new int[rez.size];
    for (int i = 0; i < rez; size; i++)
    {
        if (i < this->size)
            rez.ptr[i] = this->ptr[i];
        else
            rez.ptr[i] = 0;
    }
    return rez;
}
DynamicArray DynamicArray:: operator-(int b)
{
    DynamicArray rez;
    if (this->size > 2)
    {
        rez.size = this->size - 2;
        rez.ptr = new int[rez.size];
        for (int i = 0; i < rez.size; i++)
        {
            rez.ptr[i] = this->ptr[i];
        }
    }
    else
    {
        cout << "Error. Your array containts 2 or less elements" << endl;
        return *this;
    }
}
DynamicArray DynamicArray:: operator *(int b)
{
    DynamicArray rez;
    rez.size = this->size;
    rez.ptr = new int[rez.size];
    for (int i = 0; i < rez.size; i++)
        rez.ptr[i] = this->ptr[i] * 2;
    return rez;
}
DynamicArray DynamicArray:: operator - (DynamicArray b)
{
    DynamicArray rez;
    if (this->size > b.size)
    {
        rez.size = this->size - b.size;
        rez.ptr = new int[rez.size];
        for (int i = 0, j = 0; i < rez.size; i++)
        {
            if (i > b.size)
            {
                rez.ptr[j] = this->ptr[i];
                j++;
            }
        }
    }
    else if (this->size < b.size)
    {
        rez.size = b.size - this->size;
        rez.ptr = new int[rez.size];
        for (int i = 0, j = 0; i < rez.size; i++)
        {
            if (i > this->size)
            {
                rez.ptr[j] = b.ptr[i];
                j++;
            }
        }
    }
    else
    {
        rez.size = 0;
        rez.ptr = nullptr;
    }
    return rez;
}
DynamicArray DynamicArray:: operator + (DynamicArray b)
{
    DynamicArray rez;
    rez.size = this->size + b.size;
    rez.ptr = new int[rez.size];
    for (int i = 0, j = 0; i < rez.size; i++)
    {
        if (i < this->size)
        {
            rez.ptr[i] = this->ptr[i];
        }
        else
        {
            rez.ptr[i] = b.ptr[j];
            j++;
        }

    }
    return rez;
}
DynamicArray DynamicArray:: operator++()
{
    DynamicArray rez;
    rez.size = this->size + 1;
    rez.ptr = new int[rez.size];
    for (int i = 0; i < rez.size - 1; i++)
    {
        rez.ptr[i] = this->ptr[i];
    }
    rez.ptr[rez.size - 1] = 0;
    return rez;
}
DynamicArray DynamicArray:: operator --()
{
    DynamicArray rez;
    rez.size = this->size - 1;
    rez.ptr = new int[rez.size];
    for (int i = 0; i < rez.size; i++)
        rez.ptr[i] = this->ptr[i];
    return rez;
}