/**
 * In a histogram, finding a maximum rectangle area.
 * eg. {1, 2, 3, 4, 1}, {2, 3, 4} can contain a (2 * 3) rectangle, or {3, 4} can contain a (3 * 2) rectangle.
 */
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int FindMaxRectangle(vector<int> &pillars)
{
	int i = 0;	
	int maxArea = -1;
	int len = pillars.size();

	if(len == 0) { return 0; }
	if(len == 1) { return pillars[0]; }

	vector<int> left(len, 0);
	vector<int> right(len, 0);
	for(i = 1; i < len; ++i)
	{
		if(pillars[i - 1] >= pillars[i])
		{
			left[i] = left[i - 1] + 1;
		}
	}
	for(i = len - 2; i >= 0; --i)
	{
		if(pillars[i] <= pillars[i + 1])
		{
			right[i] = right[i + 1] + 1;
		}
	}
	for(i = 0; i < len; ++i)
	{
		maxArea = std::max(maxArea, (left[i] + right[i] + 1) * pillars[i]);
	}

	return maxArea;
}
int main()
{
	int data[] = {1, 2, 3, 4, 1};
	vector<int> pillars(data, data + sizeof(data) / sizeof(int));
	int maxArea = FindMaxRectangle(pillars);
	cout << maxArea << endl;
	return 0;
}