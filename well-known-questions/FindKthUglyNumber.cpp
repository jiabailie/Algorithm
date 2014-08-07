/**
 * Ugly number : if a number only can be divided by 2, 3, 5, this number is called ugly number. The first ugly number is 1.
 * Find the kth ugly number.
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
inline int minTriple(int a, int b, int c)
{
	return a < b ? (a < c ? a : c) : (b < c ? b : c);
}
int findKthUglyNumber(int index)
{
	int currIndex = 1;
	int currIndex2 = 0;
	int currIndex3 = 0;
	int currIndex5 = 0;
	int currMin = -1;
	vector<unsigned int> uglySet;

	uglySet.push_back(1);
	while(currIndex < index)
	{
		currMin = minTriple(uglySet[currIndex2] * 2, uglySet[currIndex3] * 3, uglySet[currIndex5] * 5);
		uglySet.push_back(currMin);
		
		for( ; currIndex2 <= currIndex && uglySet[currIndex2] * 2 <= uglySet[currIndex]; ++currIndex2);
		for( ; currIndex3 <= currIndex && uglySet[currIndex3] * 3 <= uglySet[currIndex]; ++currIndex3);
		for( ; currIndex5 <= currIndex && uglySet[currIndex5] * 5 <= uglySet[currIndex]; ++currIndex5);

		currIndex += 1;
	}
	return uglySet[index - 1];
}
bool isUglyNumber(unsigned int number)
{
	while(number % 2 == 0) { number /= 2; }
	while(number % 3 == 0) { number /= 3; }
	while(number % 5 == 0) { number /= 5; }
	return number == 1;
}
int findKthUglyNumberG(int index)
{
	int curNumber = 1;
	vector<unsigned int> uglySet;
	uglySet.push_back(1);
	while(uglySet.size() != index)
	{
		for(curNumber = curNumber + 1; ; ++curNumber)
		{
			if(isUglyNumber(curNumber))
			{
				uglySet.push_back(curNumber);
				break;
			}
		}
	}
	return uglySet[index - 1];
}
int main()
{
	int index = 600;
	int uglyNumber1 = findKthUglyNumber(index);
	int uglyNumber2 = findKthUglyNumberG(index);
	cout << "Fast Method:" << uglyNumber1 << endl;
	cout << "Slow Method:" << uglyNumber2 << endl;
	return 0;
}