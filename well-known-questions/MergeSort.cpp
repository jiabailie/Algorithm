#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define UP2BOTTOM
#undef  UP2BOTTOM

using namespace std;

const int n = 7;

inline int imin(int a, int b) { return a <= b ? a : b; }

void makeArray(vector<int> &aryObj)
{
	for(int i = 0; i < n; ++i)
	{
		aryObj.push_back(rand() % 1937);
	}
}

void displayArray(vector<int> &aryObj)
{
	for(int i = 0; i < n; ++i)
	{
		cout << aryObj[i] << " ";
	}
	cout << endl << endl;
}

void displaySortArray(vector<int> &aryObj)
{
	vector<int> cpyObj(aryObj.begin(), aryObj.end());
	sort(cpyObj.begin(), cpyObj.end());
	displayArray(cpyObj);
}

void merge(int startPos, int midPos, int endPos, vector<int> &aryObj)
{
	int i = 0, j = 0;
	vector<int> mergeRes;
	for(i = startPos, j = midPos; i < midPos && j <= endPos; )
	{
		if(aryObj[i] < aryObj[j])
		{
			mergeRes.push_back(aryObj[i]);
			i += 1;
		}
		else if(aryObj[i] > aryObj[j])
		{
			mergeRes.push_back(aryObj[j]);
			j += 1;
		}
		else if(aryObj[i] == aryObj[j])
		{
			mergeRes.push_back(aryObj[i]);
			mergeRes.push_back(aryObj[j]);
			i += 1;
			j += 1;
		}
	}
	while(i < midPos)
	{
		mergeRes.push_back(aryObj[i]);
		i += 1;
	}
	while(j <= endPos)
	{
		mergeRes.push_back(aryObj[j]);
		j += 1;
	}
	for(i = 0; i < mergeRes.size(); ++i)
	{
		aryObj[i + startPos] = mergeRes[i];
	}
}

void merge_up2bottom_sub(int startPos, int endPos, vector<int> &sortObj)
{
	int midPos = imin(endPos, startPos + (endPos - startPos) / 2 + 1);

	if(midPos == startPos && midPos == endPos) { return; }

	if(midPos - startPos == 1 && endPos == midPos)
	{
		merge(startPos, midPos, endPos, sortObj);
		return;
	}
	
	if(startPos <= midPos - 1)
	{
		merge_up2bottom_sub(startPos, midPos - 1, sortObj);
	}
	
	if(midPos <= endPos)
	{
		merge_up2bottom_sub(midPos, endPos, sortObj);
	}

	merge(startPos, midPos, endPos, sortObj);
}

void merge_up2bottom(vector<int> &sortObj)
{
	if(sortObj.size() < 2) { return; }
	merge_up2bottom_sub(0, sortObj.size() - 1, sortObj);
}

void merge_bottom2up(vector<int> &sortObj)
{
	int i = 0, j = 0;
	int start = 0, end = 0, mid = 0;
	for(i = 1; i <= sortObj.size(); i <<= 1)
	{
		for(j = 0; j < sortObj.size(); j += (i << 1))
		{
			start = j;
			end = imin(sortObj.size() - 1, j + (i << 1) - 1);
			if(start == end) { continue; }
			mid = start + i;
			merge(start, mid, end, sortObj);
		}
	}
}

void mergeSort(vector<int> &sortObj)
{
#ifdef	UP2BOTTOM
	merge_up2bottom(sortObj);
#else
	merge_bottom2up(sortObj);
#endif
}

int main()
{
	vector<int> sortObj;

	makeArray(sortObj);

	displayArray(sortObj);

	displaySortArray(sortObj);

	mergeSort(sortObj);

	displayArray(sortObj);
	
	return 0;
}