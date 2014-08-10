/**
 * In a ordered array, counting the appearance times of x.
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int findStartPosition(int num, vector<int> &orderArray)
{
	int startPos = 0;
	int midPos = 0;
	int endPos = orderArray.size() - 1;
	while(startPos <= endPos)
	{
		midPos = startPos + (endPos - startPos) / 2;
		if(orderArray[midPos] == num)
		{
			if(midPos == 0 || orderArray[midPos - 1] < num)
			{
				return midPos;
			}
			if(orderArray[midPos - 1] == num)
			{
				endPos = midPos - 1;
			}
		}
		else if(orderArray[midPos] < num)
		{
			startPos = midPos + 1;
		}
		else if(orderArray[midPos] > num)
		{
			endPos = midPos - 1;
		}
	}
	return -1;
}
int findEndPosition(int num, vector<int> &orderArray)
{
	int startPos = 0;
	int midPos = 0;
	int endPos = orderArray.size() - 1;
	while(startPos <= endPos)
	{
		midPos = startPos + (endPos - startPos) / 2;
		if(orderArray[midPos] == num)
		{
			if(midPos == orderArray.size() - 1 || orderArray[midPos + 1] > num)
			{
				return midPos;
			}
			if(orderArray[midPos + 1] == num)
			{
				startPos = midPos + 1;
			}
		}
		else if(orderArray[midPos] < num)
		{
			startPos = midPos + 1;
		}
		else if(orderArray[midPos] > num)
		{
			endPos = midPos - 1;
		}
	}

	return -1;
}
int findAppearanceTimes(int num, vector<int> &orderArray)
{
	int arraySize = orderArray.size();
	if(arraySize == 0 || num < orderArray[0] || num > orderArray[arraySize - 1])
	{
		return 0;
	}
	int startPos = findStartPosition(num, orderArray);
	int endPos = findEndPosition(num, orderArray);

	if(startPos == -1 || endPos == -1)
	{
		return 0;
	}

	return endPos - startPos + 1;
}
int main()
{
	int data[] = {1, 2, 3, 3, 5, 6, 8, 9, 3, 1};
	int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	vector<int> orderArray(data, data + sizeof(data) / sizeof(int));

	sort(orderArray.begin(), orderArray.end());

	for(vector<int>::iterator it = orderArray.begin(); it != orderArray.end(); ++it)
	{
		cout << (*it) << " ";
	}
	cout << endl;

	for(int i = 0; i < sizeof(num) / sizeof(int); ++i)
	{
		int find = findAppearanceTimes(num[i], orderArray);
		cout << "find " << num[i] << " appears " << find << " times." << endl;
	}

	return 0;
}