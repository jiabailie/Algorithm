/**
 * Suppose here is an integer array, to find out whether there is a continuous sub-array which sum is 0.
 * eg.
 * {16,-8,9,-25,-6,-1,3,-17,-13,-11,-20,20,6,2,-14,16,20,17,2,11}
 * Since -20 + 20 = 0, the result is true.
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include "common.h"
using namespace std;

bool containsSubSumIsZero(const vector<int> &arrayObj)
{
	int i = 0, j = 0;
	int preSum = 0;
	int len = arrayObj.size();
	map<int, vector<int> > subSum;
	for(i = 0; i < len; ++i)
	{
		preSum += arrayObj[i];
		if(subSum.find(preSum) == subSum.end())
		{
			subSum[preSum] = vector<int>();			
		}
		subSum[preSum].push_back(i);
		if(subSum[preSum].size() >= 2)
		{
			sort(subSum[preSum].begin(), subSum[preSum].end());
			for(j = subSum[preSum][0] + 1; j <= subSum[preSum][1]; ++j)
			{
				cout << arrayObj[j] << " ";
			}
			cout << endl;
			return true;
		}
	}
	return false;
}

int main()
{
	vector<int> arrayObj;

	makeArrayWithMinus(arrayObj);

	displayArray(arrayObj);

	bool contains = containsSubSumIsZero(arrayObj);

	return 0;
}