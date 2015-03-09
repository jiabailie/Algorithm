#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void displayVec(vector<int> &curr)
{
	for(vector<int>::iterator it = curr.begin(); it != curr.end(); ++it)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}

void solveSub(int lastIndex, int target, vector<int> &candidates, vector<int> curr)
{
	int sum = 0, i = 0;
	for(i = 0; i < curr.size(); ++i)
	{
		sum += curr[i];
	}
	if(sum > target) { return; }
	if(sum == target)
	{
		displayVec(curr);
	}
	for(i = lastIndex; i < candidates.size(); ++i)
	{
		if(sum + candidates[i] <= target)
		{
			curr.push_back(candidates[i]);
			solveSub(i, target, candidates, curr);
			curr.pop_back();
		}
	}
}

void solve(int target, vector<int> &candidates) 
{
	vector<int> curr;
	solveSub(0, target, candidates, curr);
}

int main()
{
	int target = 7;
	int candidates[] = {2, 3, 6, 7};

	vector<int> vec(candidates, candidates + (sizeof(candidates) / sizeof(int)));
	solve(target, vec);

	return 0;
}