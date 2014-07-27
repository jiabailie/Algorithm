#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define BOTTOM2UP
#undef  BOTTOM2UP
#define UP2BOTTOM
//#undef  UP2BOTTOM

using namespace std;

const int n = 13;

void makeArray(vector<int> &sortObj)
{
	for(int i = 0; i < n; ++i)
	{
		sortObj.push_back(rand() % 137);
	}
}

void displayArray(const vector<int> &sortObj)
{
	for(int i = 0; i < sortObj.size(); ++i)
	{
		cout << sortObj[i] << " ";
	}
	cout << endl << endl;
}

void displaySortArray(const vector<int> &sortObj)
{
	vector<int> cpyObj(sortObj.begin(), sortObj.end());
	sort(cpyObj.begin(), cpyObj.end());
	displayArray(cpyObj);
}

void iMerge(int startPos, int midPos, int endPos, vector<int> &sortObj)
{
	if(startPos < 0 || endPos >= sortObj.size() || !(startPos < midPos && midPos <= endPos) || sortObj.size() < 2)
	{
		return;
	}
	int i = 0, j = 0;
	vector<int> tmpObj;
	for(i = startPos, j = midPos; i < midPos && j <= endPos; )
	{
		if(sortObj[i] < sortObj[j])
		{
			tmpObj.push_back(sortObj[i]);
			i += 1;
		}
		else if(sortObj[i] > sortObj[j])
		{
			tmpObj.push_back(sortObj[j]);
			j += 1;
		}
		else
		{
			tmpObj.push_back(sortObj[i]);
			tmpObj.push_back(sortObj[j]);
			i += 1;
			j += 1;
		}
	}
	while(i < midPos)
	{
		tmpObj.push_back(sortObj[i]);
		i += 1;
	}
	while(j <= endPos)
	{
		tmpObj.push_back(sortObj[j]);
		j += 1;
	}
	for(i = 0; i < tmpObj.size(); ++i)
	{
		sortObj[startPos + i] = tmpObj[i];
	}
}

void merge_up2bottom_sub(int startPos, int endPos, vector<int> &sortObj)
{
	if(startPos == endPos)
	{
		return;
	}
	if(endPos - startPos == 1)
	{
		iMerge(startPos, endPos, endPos, sortObj);
		return;
	}
	int midPos = startPos + (endPos - startPos + 3) / 2;
	merge_up2bottom_sub(startPos, midPos - 1, sortObj);
	merge_up2bottom_sub(midPos, endPos, sortObj);
	iMerge(startPos, midPos, endPos, sortObj);
}

void merge_bottom2up(vector<int> &sortObj)
{
	int i = 0, j = 0;
	int startPos = 0;
	int midPos = 0;
	int endPos = 0;
	for(i = 1; i < sortObj.size(); i <<= 1)
	{
		for(j = 0; j < sortObj.size(); j += 2 * i)
		{
			startPos = j;
			midPos = std::min<int>(sortObj.size() - 1, j + i);
			endPos = std::min<int>(sortObj.size() - 1, j + 2 * i - 1);
			iMerge(startPos, midPos, endPos, sortObj);
		}
	}
}

void merge_up2bottom(vector<int> &sortObj)
{
	merge_up2bottom_sub(0, sortObj.size() - 1, sortObj);
}

void mergesort(vector<int> &sortObj)
{
	if(sortObj.size() < 2)
	{
		return;
	}
#ifdef BOTTOM2UP
	merge_bottom2up(sortObj);
#endif

#ifdef UP2BOTTOM
	merge_up2bottom(sortObj);
#endif
}

int main()
{
	vector<int> sortArray;

	makeArray(sortArray);

	displayArray(sortArray);

	displaySortArray(sortArray);

	mergesort(sortArray);

	displayArray(sortArray);

	return 0;
}