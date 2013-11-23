/* There are n children, each one has a weight[i].
 * Each child should get at least one candy.
 * Return the minimum amount of candy should prepare for the assignment.
 * For children[i], if weight[i] > weight[i - 1], then children[i] should get more candy than children[i - 1];
 * For children[i], if weight[i] < weight[i - 1], then children[i] should get less candy than children[i - 1].
 * Input: weight[] = {}
 * Output: assignment[] = {}
 * Reference: mp.weixin.qq.com/mp/appmsg/show?__biz=MjM5ODIzNDQ3Mw==&appmsgid=10000279&itemidx=1&sign=3cae5f5182cc0a7c1bfc8d09ba4dbc3d
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#define DEBUG
#undef	DEBUG

using namespace std;

struct compressNode
{
	int weight;
	int wave; // 0 normal, 1 crest, -1 trough
	int candy;
	int start;
	int end;
	compressNode(int _weight, int _start, int _end) : weight(_weight), start(_start), end(_end), wave(0), candy(0) {}
	bool operator<(const compressNode& right) const { return weight < right.weight; }
	bool operator>(const compressNode& right) const { return weight > right.weight; }
};

void compressWeight(vector<int>& weight, vector<compressNode>& weightCompress)
{
	int i = 0, j = 0;
	int n = weight.size();

	weightCompress.clear();
	for(i = 0; i < n; i++)
	{
		if(weightCompress.size() == 0 || (weightCompress.size() > 0 && weightCompress.back().weight != weight[i]))
		{
			weightCompress.push_back(compressNode(weight[i], i, i));
			continue;
		}
		// weightCompress.size() > 0
		if(weightCompress.back().weight == weight[i])
		{
			weightCompress.back().end = i;
		}
	}
}

void assignCandy(vector<int>& assignment, vector<int>& weight)
{
	int i = 0, j = 0, n = 0;
	vector<compressNode> weightCompress;
	compressWeight(weight, weightCompress);

	n = weightCompress.size();
	weightCompress[0].wave = 1;
	if(weightCompress[0] < weightCompress[1]) { weightCompress[0].wave = -1; }
	for(i = 1; i < n - 1; i++)
	{
		if(weightCompress[i] > weightCompress[i - 1] && weightCompress[i] > weightCompress[i + 1]) 
		{ weightCompress[i].wave = 1; }
		
		if(weightCompress[i] < weightCompress[i - 1] && weightCompress[i] < weightCompress[i + 1]) 
		{ weightCompress[i].wave = -1; }
	}
	weightCompress[n - 1].wave = 1;
	if(weightCompress[n - 1] < weightCompress[n - 2]) { weightCompress[n - 1].wave = -1; }

	for(i = 0; i < n; i++)
	{
		if(weightCompress[i].wave == -1)
		{
			weightCompress[i].candy = 1;
			for(j = i + 1; j < n && weightCompress[j - 1].wave != 1; j++)
			{
				weightCompress[j].candy = weightCompress[j - 1].candy + 1;
			}
			i = j - 1;
		}		
	}
	for(i = n - 1; i >= 0; i--)
	{
		if(weightCompress[i].wave == -1)
		{
			for(j = i - 1; j >= 0 && weightCompress[j].wave != 1; j--)
			{
				weightCompress[j].candy = weightCompress[j + 1].candy + 1;
			}
			i = j;
		}
	}
	for(i = 0; i < n; i++)
	{
		for(j = weightCompress[i].start; j <= weightCompress[i].end; j++)
		{
			assignment.push_back(weightCompress[i].candy);
		}
	}
}

int main()
{
	int i = 0;
	int n = 0;
	int t = 0;
	vector<int> weight;
	vector<int> assignment;

#ifdef DEBUG
	int data[] = //{1,2,3,4,2,6};
		     {1,2,3,4,5,5,6,7,3,2,2,1,5};
	n = sizeof(data) / sizeof(int);
	for each(int x in data)
	{
		weight.push_back(x);
	}
#else
	cin >> n;

	for(i = 0; i < n; i++)
	{
		cin >> t;
		weight.push_back(t);
	}
#endif

	assignCandy(assignment, weight);

	return 0;
}
