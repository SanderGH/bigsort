// bigsort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <chrono>
#include <algorithm>
#include "template.h"

using namespace std;
using namespace std::chrono;

// stability algoritms
template<class T>
auto BubbleSort(vector<T> vec)
{
	size_t compareCount = 0, swapCount = 0;
	auto size = vec.size();
	for( int i = 0; i < size -1 ; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			++compareCount;
			if (vec[j] > vec[j + 1])
			{
				std::swap(vec[j], vec[j + 1]);
				++swapCount;
			}
		}
	}

	cout << "compare - " << compareCount << ", swap - " << swapCount <<endl;
	return vec;
}

template<class T>
auto InsertionSort(vector<T> vec)
{
	size_t compareCount = 0, swapCount = 0;
	for(int i = 0; i < vec.size()-1; i++)
	{
		int j = i + 1;

		while( j > 0  && vec[j] < vec[j-1])
		{ 
			++compareCount; ++swapCount;
			swap(vec[j], vec[j - 1]);
			--j;
		}
	}

	cout << "compare - " << compareCount << ", swap - " << swapCount << endl;
	return vec;
}


// not stability algoritms
template<class T>
vector<T> SelectionSort(vector<T> vec)
{
	size_t compareCount = 0, swapCount = 0;
	auto size = vec.size();
	for (int i = 0; i < size - 1; i++)
	{
		auto minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			++compareCount;
			if (vec[j] < vec[minIndex])
				minIndex = j;
		}
		
		if (minIndex != i)
		{
			std::swap(vec[i], vec[minIndex]);
			++swapCount;
		}

	}

	cout << "compare - " << compareCount << ", swap - " << swapCount << endl;
	return vec;
}


int main()
{
	vector<int> vec(2000);
	for (auto& i : vec)
		i = rand();
	//cout << vec << endl;

	cout << " *** Bubble sort Period ***" << endl;
	auto start = steady_clock::now();
	auto bubble = BubbleSort(vec);
	auto end = steady_clock::now();
	auto elapsed = duration_cast<milliseconds>(end - start);
	cout << "Period = " << elapsed.count() << "ms" << endl;

	cout << endl << " *** Selection sort Period ***" << endl;
	start = steady_clock::now();
	auto selection =  SelectionSort(vec);
	end = steady_clock::now();
	elapsed = duration_cast<milliseconds>(end - start);
	cout << "Period = " << elapsed.count() << "ms" << endl;

	cout << endl << " *** Insertion sort Period ***" << endl;
	start = steady_clock::now();
	auto insertion = InsertionSort(vec);
	end = steady_clock::now();
	elapsed = duration_cast<milliseconds>(end - start);
	cout << "Period = " << elapsed.count() << "ms" << endl;

	if( bubble == selection && insertion == selection )
		cout << "Arries are equal \n";
}