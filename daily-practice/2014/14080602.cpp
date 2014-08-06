#include <cstdio>
#include <iostream>
using namespace std;
bool JudgeValidBalanceBinaryTreePostTraverse(int startPos, int endPos, const char *posOrder)
{
	if(!(posOrder && startPos >= 0 && startPos <= endPos && endPos < strlen(posOrder))) { return false; }
	if(startPos == endPos) { return true; }
	int i = startPos;
	int pivotPos = -1;
	for(i = startPos; i < endPos; ++i)
	{
		if(posOrder[i] >= posOrder[endPos])
		{
			pivotPos = i;
			break;
		}
	}
	// if pivotPos == -1, which means the elements between posOrder[startPos] and posOrder[endPos - 1] are all less than posOrder[endPos];
	if(pivotPos == -1)
	{
		for(i = startPos; i < endPos; ++i)
		{
			if(posOrder[i] >= posOrder[endPos])
			{
				return false;
			}
		}
		return JudgeValidBalanceBinaryTreePostTraverse(startPos, endPos - 1, posOrder);
	}
	// if pivotPos == startPos, which means the elements between posOrder[startPos] and posOrder[endPos - 1] are all equal or larger than posOrder[endPos];
	else if(pivotPos == startPos)
	{
		for(i = startPos; i < endPos; ++i)
		{
			if(posOrder[i] < posOrder[endPos])
			{
				return false;
			}
		}
		return JudgeValidBalanceBinaryTreePostTraverse(startPos, endPos - 1, posOrder);
	}
	// if pivotPos is between startPos and endPos - 1, which means the elements between posOrder[startPos] and posOrder[pivotPos - 1] are all less than posOrder[endPos],
	// and meanwhile, the elements between posOrder[pivotPos] and posOrder[endPos - 1] are all equal or larger than posOrder[endPos].
	else if(pivotPos > startPos && pivotPos < endPos)
	{
		for(i = startPos; i < pivotPos; ++i)
		{
			if(posOrder[i] >= posOrder[endPos])
			{
				return false;
			}
		}
		for(i = pivotPos; i < endPos; ++i)
		{
			if(posOrder[i] < posOrder[endPos])
			{
				return false;
			}
		}
		return JudgeValidBalanceBinaryTreePostTraverse(startPos, pivotPos - 1, posOrder) && JudgeValidBalanceBinaryTreePostTraverse(pivotPos, endPos - 1, posOrder);
	}
	return false;
}
int main()
{
	char *posOrder = "2436875";

	bool legal = JudgeValidBalanceBinaryTreePostTraverse(0, strlen(posOrder) - 1, posOrder);

	cout << posOrder << endl << (legal ? "legal" : "illegal") << endl;

	return 0;
}