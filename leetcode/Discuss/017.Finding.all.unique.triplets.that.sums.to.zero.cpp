#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

set<vector<int> > find_triplets1(vector<int> arr)
{
	int curr = 1, next = 0;
	map<int, vector<vector<int> > > dp[2];
	for(int i = 0; i < arr.size(); ++i)
	{
		curr = (curr + 1) % 2;
		next = (next + 1) % 2;
		dp[next].clear();
		for(map<int, vector<vector<int> > >::iterator it = dp[curr].begin(); it != dp[curr].end(); ++it)
		{			
			for(vector<vector<int> >::iterator iit = it->second.begin(); iit != it->second.end(); ++iit)
			{
				if(iit->size() > 3) { continue; }
				dp[next][it->first].push_back(vector<int>(iit->begin(), iit->end()));
			}
			int k = it->first + arr[i];
			for(vector<vector<int> >::iterator iit = it->second.begin(); iit != it->second.end(); ++iit)
			{
				vector<int> tmp(iit->begin(), iit->end());
				tmp.push_back(arr[i]);
				if(tmp.size() > 3) { continue; }
				dp[next][k].push_back(tmp);
			}
		}
		dp[next][arr[i]].push_back(vector<int>(1, arr[i]));
	}
	set<vector<int> > ret;
	for(vector<vector<int> >::iterator it = dp[next][0].begin(); it != dp[next][0].end(); ++it)
	{
		if(it->size() == 3)
		{
			vector<int> tmp(it->begin(), it->end());
			sort(tmp.begin(), tmp.end()); // remove duplicate triples
			ret.insert(tmp);
		}
	}

	return ret;
}

set<vector<int> > find_triplets2(vector<int> arr)
{
	sort(arr.begin(), arr.end());
	set<vector<int> > triplets;
	vector<int> triplet(3);
	int n = arr.size();
	for(int i = 0; i < n; ++i)
	{
		int j = i + 1;
		int k = n - 1;
		while(j < k)
		{
			int sum_two = arr[i] + arr[j];
			if(sum_two + arr[k] < 0)
			{
				j += 1;
			}
			else if(sum_two + arr[k] > 0)
			{
				k -= 1;
			}
			else
			{
				triplet[0] = arr[i];
				triplet[1] = arr[j];
				triplet[2] = arr[k];
				triplets.insert(triplet);
				j += 1;
				k -= 1;
			}
		}
	}
	return triplets;
}

void displayVectors(set<vector<int> > &elem)
{
	for(set<vector<int> >::iterator it = elem.begin(); it != elem.end(); ++it)
	{
		for(vector<int>::const_iterator iit = it->begin(); iit != it->end(); ++iit)
		{
			cout << (*iit) << " ";
		}
		cout << endl;
	}
}

int main()
{
	int S[] = {-1, 0, 1, 2, -1, -4};
	int n = sizeof(S) / sizeof(int);

	vector<int> arr(S, S + n);

	set<vector<int> > ret = find_triplets1(arr);
	cout << "my method:" << endl;
	displayVectors(ret);

	ret = find_triplets2(arr);
	cout << "leetcode method:" << endl;
	displayVectors(ret);

	return 0;
}