/**
 * There is an integer array, which length is n. We will separate the array into m parts, and each parts have the same sum.
 * Get the maximum m.
 * eg. {3,2,4,3,6} can separate into {3, 3}, {2, 4}, {6}, thus maximum m is 3.
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
const int maxN = 1000;
bool isExist[maxN];
vector<vector<int> > dpRecord[maxN];
/* Swap two vectors. */
void swapVector(vector<int> &vecA, vector<int> &vecB)
{
	vector<int> vecC(vecA.begin(), vecA.end());
	vecA = vector<int>(vecB.begin(), vecB.end());
	vecB = vector<int>(vecC.begin(), vecC.end());
}
/* Print out a map key's vectors. */
void printVector(int currSum)
{
	cout << "Curreny sum = " << currSum << endl;
	for(vector<vector<int> >::iterator it = dpRecord[currSum].begin(); it != dpRecord[currSum].end(); ++it)
	{
		for(vector<int>::iterator iit = it->begin(); iit != it->end(); ++iit)
		{
			cout << (*iit) << " ";
		}
		cout << endl;
	}
	cout << endl;
}
/* Order vector<vector<int>> by its vectors' size. */
void orderVectorBySize(int currSum)
{
	if(dpRecord[currSum].size() < 2)
	{
		return;
	}
	int i = 0, j = 0;
	for(i = 0; i < dpRecord[currSum].size() - 1; ++i)
	{
		for(j = i + 1; j < dpRecord[currSum].size(); ++j)
		{
			if(dpRecord[currSum][i].size() > dpRecord[currSum][j].size())
			{
				swapVector(dpRecord[currSum][i], dpRecord[currSum][j]);
			}
		}
	}
}
int getMaxParts(int currSum, vector<int> &arrayObj)
{
	int maySeparate = 0;
	bool canAssign = true;
	map<int, int> remainNum;
	map<int, int> tmpNum;
	for(vector<int>::iterator it = arrayObj.begin(); it != arrayObj.end(); ++it)
	{
		if(remainNum.find(*it) == remainNum.end())
		{
			remainNum[*it] = 0;
		}
		remainNum[*it] += 1;
	}
	for(vector<vector<int> >::iterator it = dpRecord[currSum].begin(); it != dpRecord[currSum].end(); ++it)
	{
		if(it->size() == 0) { continue; }
		tmpNum.clear();
		for(vector<int>::iterator iit = it->begin(); iit != it->end(); ++iit)
		{
			if(tmpNum.find(*iit) == tmpNum.end())
			{
				tmpNum[*iit] = 0;
			}
			tmpNum[*iit] += 1;
		}
		canAssign = true;
		for(map<int, int>::iterator mit = tmpNum.begin(); mit != tmpNum.end(); ++mit)
		{
			if(mit->second > remainNum[mit->first])
			{
				canAssign = false;
			}
		}
		if(canAssign)
		{
			maySeparate += 1;
			for(map<int, int>::iterator mit = tmpNum.begin(); mit != tmpNum.end(); ++mit)
			{
				remainNum[mit->first] -= mit->second;
			}
		}
	}
	return maySeparate;
}
int getMaxSeparate(vector<int> &arrayObj)
{
	memset(isExist, 0, sizeof(isExist));
	isExist[0] = true;
	dpRecord[0].push_back(vector<int>());
	int i = 0, j = 0;
	for(i = 0; i < arrayObj.size(); ++i)
	{
		for(j = maxN - 1; j >= 0; --j)
		{
			if(isExist[j])
			{
				isExist[j + arrayObj[i]] = true;
				for(vector<vector<int> >::iterator it = dpRecord[j].begin(); it != dpRecord[j].end(); ++it)
				{
					vector<int> vecTmp(it->begin(), it->end());
					vecTmp.push_back(arrayObj[i]);
					dpRecord[j + arrayObj[i]].push_back(vector<int>(vecTmp.begin(), vecTmp.end()));
				}
			}
		}
	}
	int maxParts = 0;
	for(i = 0; i < maxN && maxParts < arrayObj.size(); ++i)
	{
		if(isExist[i] && dpRecord[i].size() > maxParts)
		{
			orderVectorBySize(i);
			printVector(i);
			j = getMaxParts(i, arrayObj);
			if(j > maxParts)
			{
				maxParts = j;
			}
		}
	}
	return maxParts;
}
int main()
{
	int data[] = {3,2,4,3,6};

	vector<int> arrayObj(data, data + sizeof(data) / sizeof(int));

	int maxParts = getMaxSeparate(arrayObj);

	cout << maxParts << endl;

	return 0;
}