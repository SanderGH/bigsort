// bigsort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <chrono>

using namespace std;

template<class T>
void BubbleSort(vector<T>& vec)
{
	int size = vec.size();
	for( int i = 0; i < size -1 ; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (vec[j] > vec[j+1])
				std::swap( vec[j], vec[j+1]);
		}
	}
}
void map()
{
}

void reduce()
{
}

int main()
{
	std::chrono::duration<int> sss(20);
	std::ratio<22, 1> k;
	vector<int> vec{23,5,7,12,89,3,21,12,34,6};
	BubbleSort(vec);
    std::cout << "Hello World!\n"; 
}