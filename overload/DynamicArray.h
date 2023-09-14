#pragma once
#include <iostream>
using namespace std;
class DynamicArray
{
	int* ptr; // óêàçàòåëü íà äèíàì. ìàññèâ
	int size;  // ðàçìåð ìàññèâà 
public:
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&); // copy constructor
	~DynamicArray();
	void Input();// rand
	void Output()const;// âûâîä íà êîíñîëü
	int* GetPointer()const;
	int GetSize()const;
	DynamicArray operator+(int b);
	DynamicArray operator-(int b);
	DynamicArray operator *(int b);
	DynamicArray operator - (DynamicArray b);
	DynamicArray operator + (DynamicArray b);
	DynamicArray operator++();
	DynamicArray operator--();







};