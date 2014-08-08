/**
 * In a number set, if only one number appears once, and all the other numbers are all appears twice, we can use xor to get the number.
 * Furthermore, if there are two numbers appears once, we can use the similar idea, but use 'some bit' to split the array into two parts,
 * and use the same method to find them.
 * some bit: if we do xor operation towars the data set, if the result is not 0, which means its certain bit is 1, suppose a and b are the two numbers,
 * if a is not equal to b, a ^ b != 0, and the xor operation of other numbers is 0, thus we can use this bit to do separation.
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vecPow;

int calcXor(vector<int> &number)
{
	int ret = 0;
	for(vector<int>::iterator it = number.begin(); it != number.end(); ++it)
	{
		ret ^= (*it);
	}
	return ret;
}

void generatePow()
{
	vecPow.clear();
	for(int i = 0; i < 32; ++i)
	{
		vecPow.push_back(1 << i);
	}
}

int getBitIs1(int number)
{
	for(vector<int>::iterator it = vecPow.begin(); it != vecPow.end(); ++it)
	{
		if(number & (*it))
		{
			return (*it);
		}
	}
	throw std::exception("The number is overflow.");
}

int findSingleNumber(vector<int> &number)
{
	int ret = 0;
	for(vector<int>::iterator it = number.begin(); it != number.end(); ++it)
	{
		ret ^= (*it);
	}
	return ret;
}

vector<int> findTwoSingleNumber(vector<int> &number)
{
	int xor = 0;
	int bitPos = 1;
	vector<int> single;

	if(number.size() == 0) 
	{ 
		return single; 
	}

	generatePow();
	xor = calcXor(number);

	if(xor == 0) 
	{ 
		std::exception("Invalid input."); 
	}

	bitPos = getBitIs1(xor);

	vector<int> bitIs0;
	vector<int> bitIs1;

	for(vector<int>::iterator it = number.begin(); it != number.end(); ++it)
	{
		if(bitPos & (*it))
		{
			bitIs1.push_back(*it);
		}
		else
		{
			bitIs0.push_back(*it);
		}
	}

	single.push_back(findSingleNumber(bitIs0));
	single.push_back(findSingleNumber(bitIs1));

	return single;
}
int main()
{
	int number[] = {1, 1, 3, 4, 4, 5, 6, 7, 8, 6, 7, 8};

	vector<int> vecNum(number, number + sizeof(number) / sizeof(int));

	sort(vecNum.begin(), vecNum.end());

	vector<int> single = findTwoSingleNumber(vecNum);

	for(vector<int>::iterator it = single.begin(); it != single.end(); ++it)
	{
		cout << (*it) << " ";
	}
	cout << endl;

	return 0;
}