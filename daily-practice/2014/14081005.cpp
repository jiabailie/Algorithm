/**
 * In a histogram, finding a maximum rectangle area.
 * eg. {1, 2, 3, 4, 1}, {2, 3, 4} can contain a (2 * 3) rectangle, or {3, 4} can contain a (3 * 2) rectangle.
 */
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <stack>
#define USE_FUNCTION
#undef  USE_FUNCTION
using namespace std;

void InitialParams(int startPos, int endPos, int direction, vector<int> &pillars, vector<int> &param)
{
	int i = 0, top = 0;
	stack<int> stackPillar;
	stackPillar.push(startPos);
	startPos += direction;
	for(i = startPos; i != endPos; i += direction)
	{
		if(pillars[i] < pillars[stackPillar.top()])
		{
			while(!stackPillar.empty() && pillars[i] <= pillars[stackPillar.top()])
			{
				top = stackPillar.top();
				stackPillar.pop();
			}
			stackPillar.push(top);
			param[i] = std::abs(i - top);
		}
		stackPillar.push(i);
	}
}

int FindMaxRectangle(vector<int> &pillars)
{
	int i = 0;
	int len = pillars.size();

	if(len == 0) { return 0; }

	if(len == 1) { return pillars[0]; }

	int top = 0;
	stack<int> stackPillar;
	vector<int> left(len, 0);
	vector<int> right(len, 0);
#ifdef USE_FUNCTION
	InitialParams(0, len, 1, pillars, left);

	InitialParams(len - 1, -1, -1, pillars, right);
#else
	stackPillar.push(0);
	for(i = 1; i < len; ++i)
	{
		if(pillars[i] < pillars[stackPillar.top()])
		{
			while(!stackPillar.empty() && pillars[i] <= pillars[stackPillar.top()])
			{
				top = stackPillar.top();
				stackPillar.pop();
			}
			stackPillar.push(top);
			left[i] = i - top;
		}
		stackPillar.push(i);
	}
	
	while(!stackPillar.empty()) { stackPillar.pop(); }
	stackPillar.push(len - 1);
	for(i = len - 2; i >= 0; --i)
	{
		if(pillars[i] < pillars[stackPillar.top()])
		{
			while(!stackPillar.empty() && pillars[i] <= pillars[stackPillar.top()])
			{
				top = stackPillar.top();
				stackPillar.pop();
			}
			stackPillar.push(top);
			right[i] = top - i;
		}
		stackPillar.push(i);
	}
#endif

	int maxArea = 0;

	for(i = 0; i < len; ++i)
	{
		maxArea = std::max(maxArea, (left[i] + right[i] + 1) * pillars[i]);
	}

	return maxArea;
}
int main()
{
	int rawdata[] = { 1, 3, 5, 1, 8, 6, 7, 5 };

	vector<int> pillars(rawdata, rawdata + sizeof(rawdata) / sizeof(int));

	int maxArea = FindMaxRectangle(pillars);

	cout << maxArea << endl;

	return 0;
}