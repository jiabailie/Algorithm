/**
 * Suppose there is an array, and another demand number.
 * Find out all possible combinations which can sum up to the demand number.
 * eg.
 * Array = {1, 2, 3, 4, 5, 6, 7, 8, 9}, demand number = 10.
 * Result: 
 * 1 2 3 4
 * 2 3 5
 * 1 4 5
 * 1 3 6
 * 4 6
 * 1 2 7
 * 3 7
 * 2 8
 * 1 9
 */
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
const int maxN = 100;
bool dp[maxN];
std::vector<std::vector<int> > combinations[maxN];
void PrintVector(std::vector<int> &subSet)
{
	for(std::vector<int>::iterator it = subSet.begin(); it != subSet.end(); ++it)
	{
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
}
void PrintDemandCombinations(int demandNumber, std::vector<int> &numSet)
{
	if(demandNumber >= maxN)
	{
		std::cout << "The demand number is larger than the maximum limitition." << std::endl;
	}
	dp[0] = true;
	int i = 0, j = 0;
	for(i = 0; i < numSet.size(); ++i)
	{
		for(j = maxN - 1 - numSet[i]; j >= 0; --j)
		{
			if(dp[j])
			{				
				if(combinations[j].size() == 0)
				{
					std::vector<int> tmp;
					tmp.push_back(numSet[i]);
					dp[j + numSet[i]] = true;
					combinations[j + numSet[i]].push_back(std::vector<int>(tmp.begin(), tmp.end()));
				}
				else
				{
					for(std::vector<std::vector<int> >::iterator it = combinations[j].begin(); it != combinations[j].end(); ++it)
					{
						std::vector<int> tmp((*it).begin(), (*it).end());
						tmp.push_back(numSet[i]);
						dp[j + numSet[i]] = true;
						combinations[j + numSet[i]].push_back(std::vector<int>(tmp.begin(), tmp.end()));
					}
				}
			}
		}
	}
	if(!dp[demandNumber])
	{
		std::cout << "There is no possible combinations which can sum up to the demand number." << std::endl;
	}
	else
	{
		for(std::vector<std::vector<int> >::iterator it = combinations[demandNumber].begin(); it != combinations[demandNumber].end(); ++it)
		{
			PrintVector(*it);
		}
	}
}
int main()
{
	int i = 0;
	int demandNumber = 10;
	std::vector<int> numSet;
	std::vector<int> subSet;
	for(i = 1; i < 10; ++i)
	{
		numSet.push_back(i);
	}
	memset(dp, 0, sizeof(dp));
	for(i = 0; i < maxN; ++i)
	{
		combinations[i] = std::vector<std::vector<int> >();
	}
	std::sort(numSet.begin(), numSet.end());
	PrintDemandCombinations(demandNumber, numSet);
	return 0;
}