/**
 * There is a unordered integer array, finding all difference triple combinations (a, b, c), which can composed a triangle.
 * eg. {4, 6, 3, 7}
 * output: {3, 4, 6}, {3, 6, 7}, {4, 6, 7}.
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
inline bool judgeTriangle(int e1, int e2, int e3)
{
	if(e1 + e2 > e3 && e1 + e3 > e2 && e2 + e3 > e1)
	{
		return true;
	}
	return false;
}
// Find the first element's position which is less than value.
// data[result] < value, data[result + 1] >= value (if result + 1 < data.size()).
int FindLeftPosition(int value, vector<int> &data)
{
	int len = data.size();
	if(data[len - 1] < value) { return len - 1; }
	if(data[0] >= value) { return -1; }
	int startPos = 0;
	int endPos = len - 1;
	int midPos = 0;
	while(startPos <= endPos)
	{
		midPos = startPos + (endPos - startPos) / 2;
		if(data[midPos] == value)
		{
			if(midPos - 1 >= 0 && data[midPos - 1] < value)
			{
				return midPos - 1;
			}
			endPos = midPos - 1;
		}
		else if(data[midPos] < value)
		{
			if(midPos + 1 < len && data[midPos + 1] >= value)
			{
				return midPos;
			}
			startPos = midPos + 1;
		}
		else if(data[midPos] > value)
		{
			if(midPos - 1 >= 0 && data[midPos - 1] < value)
			{
				return midPos - 1;
			}
			endPos = midPos - 1;
		}
	}
	return -1;
}
// Find the first element's position which is larger than value.
// value < data[result], data[result - 1] <= value (if result - 1 >= 0).
int FindRightPosition(int value, vector<int> &data)
{
	int len = data.size();
	if(data[len - 1] <= value) { return -1; }
	if(value < data[0]) { return 0; }
	int startPos = 0;
	int endPos = len - 1;
	int midPos = 0;
	while(startPos <= endPos)
	{
		midPos = startPos + (endPos - startPos) / 2;
		if(data[midPos] == value)
		{
			if(midPos + 1 < len && value < data[midPos + 1])
			{
				return midPos + 1;
			}
			startPos = midPos + 1;
		}
		else if(data[midPos] < value)
		{
			if(midPos + 1 < len && data[midPos + 1] > value)
			{
				return midPos + 1;
			}
			startPos = midPos + 1;
		}
		else if(data[midPos] > value)
		{
			if(midPos - 1 >= 0 && data[midPos - 1] < value)
			{
				return midPos;
			}
			endPos = midPos - 1;
		}
	}
	return -1;
}
void FindPossibleTriangle1(vector<int> &edges)
{
	int i = 0, j = 0, k = 0;
	for(i = 0; i < edges.size() - 2; ++i)
	{
		for(j = i + 1; j < edges.size() - 1; ++j)
		{
			for(k = j + 1; k < edges.size(); ++k)
			{
				if(judgeTriangle(edges[i], edges[j], edges[k]))
				{
					cout << edges[i] << " " << edges[j] << " " << edges[k] << endl;
				}
			}
		}
	}
	cout << endl;
}
void FindPossibleTriangle2(vector<int> &edges)
{
	int i = 0, j = 0, k = 0;
	int len = edges.size();
	int startPos = 0, endPos = 0;
	int maxValue = 0, minValue = 0;
	for(i = 0; i < len - 1; ++i)
	{
		for(j = i + 1; j < len; ++j)
		{
			maxValue = edges[i] + edges[j];
			minValue = std::abs(edges[i] - edges[j]);
			if(maxValue > edges[len - 1])
			{
				endPos = len - 1;
			}
			else
			{
				endPos = FindLeftPosition(maxValue, edges);
				if(endPos == -1)
				{
					throw std::exception("Invalid input.");
				}
			}
			if(minValue < edges[0])
			{
				startPos = 0;
			}
			else
			{
				startPos = FindRightPosition(minValue, edges);
				if(startPos == -1)
				{
					throw std::exception("Invalid input.");
				}
			}
			if(endPos <= j)
			{
				continue;
			}
			if(j + 1 < len)
			{
				for(k = std::max(startPos, j + 1); k <= endPos; ++k)
				{
					cout << edges[i] << " " << edges[j] << " " << edges[k] << endl;
				}
			}
		}
	}
	cout << endl;
}
int main()
{
	int data[] = {4, 6, 3, 7};

	vector<int> edges(data, data + sizeof(data) / sizeof(int));

	sort(edges.begin(), edges.end());

	FindPossibleTriangle2(edges);

	return 0;
}