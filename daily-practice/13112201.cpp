/*
 * Function : Practice shell sort.
 * Output	: Ascending order.
 */
#include <cstdio>
#include <vector>
#include <iostream>
#define DEBUG

using namespace std;

const int Length_Range = 60;

const int Value_Range = 1000000;

template<typename T>
inline void iswap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

/* Generate a new integer array. */
inline void generateArray(vector<int>& ary)
{
	ary.clear();

	int len = rand() % Length_Range;

	for(int i = 0; i < len; i++)
	{
		ary.push_back(rand() % Value_Range);
	}
}

/* Print out the vector. */
inline void printVector(const vector<int>& ary)
{
	for(vector<int>::const_iterator it = ary.begin(); it != ary.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}

/* Shell sort. */
inline vector<int> shellSort(int step, const vector<int>& ary)
{
	int n = ary.size(), p = 0;
	int i = 0, j = 0, k = 0;
	vector<int> ret(ary.begin(), ary.end());

	for(i = step; i > 0; i = (i >> 1))
	{
		for(j = 0; j < n; j += i)
		{
			p = j;
			for(k = j + i; k < n; k += i)
			{
				if(ret[p] > ret[k])
				{
					p = k;
				}
			}
			if(p != j)
			{
				iswap(ret[j], ret[p]);
			}
		}
	}

	return ret;
}

int main()
{
	vector<int> ary;

	generateArray(ary);

#ifdef DEBUG
	printVector(ary);
#endif

	int len = ary.size();

	vector<int> ret = shellSort(len / 3, ary);

#ifdef DEBUG
	printVector(ret);
#endif

	return 0;
}
