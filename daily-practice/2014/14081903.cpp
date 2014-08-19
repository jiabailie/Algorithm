/**
 * Print out the full permutation of an input array using nonrecursive method.
 * Idea:
 * 1. From the tail to the head to find the first combination (a, b) which satisfied a < b, and a and b are neighbours.
 * 2. From b's position to the end, finding the minimum number c which is larger than a, 
 *    which means finding the numbers {S} which are all larger than b, and c is the minimum number of {S}.
 * 3. Swap a and b.
 * 4. Reverse the substring after a.
 * 5. Return to 1, till there is no (a, b) liking pairs.
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
inline void tswap(int &a, int &b) { int c = a; a = b; b = c; }
void Reverse(int sPos, int ePos, vector<int> &arrayObj)
{
	if(sPos == ePos || !(sPos >= 0 && ePos < arrayObj.size() && sPos < ePos))
	{
		return;
	}
	while(sPos < ePos)
	{
		tswap(arrayObj[sPos], arrayObj[ePos]);
		sPos += 1;
		ePos -= 1;
	}
}
void PrintVector(int order, const vector<int> &arrayObj)
{
	cout << order << ":";
	for(vector<int>::const_iterator it = arrayObj.begin(); it != arrayObj.end(); ++it)
	{		
		cout << (*it) << " ";
	}
	cout << endl;
}
void PrintPermutation(vector<int> &arrayObj)
{
	int order = 1;
	PrintVector(order, arrayObj);
	if(arrayObj.size() == 1)
	{
		return;
	}
	int i = 0;
	int rPos = 0;
	int rMin = 0;
	int tMin = 0;
	while(true)
	{
		for(rPos = arrayObj.size() - 2; rPos >= 0; --rPos)
		{
			if(arrayObj[rPos] < arrayObj[rPos + 1])
			{
				break;
			}
		}
		if(rPos == -1) { break; }
		rMin = rPos;
		tMin = INT_MAX;
		for(i = rPos; i < arrayObj.size(); ++i)
		{
			if(arrayObj[i] > arrayObj[rPos] && arrayObj[i] < tMin)
			{
				rMin = i;
				tMin = arrayObj[i];
			}
		}
		if(rMin != rPos)
		{
			order += 1;
			tswap(arrayObj[rPos], arrayObj[rMin]);
			Reverse(rPos + 1, arrayObj.size() - 1, arrayObj);
			PrintVector(order, arrayObj);
		}
	}
}
int main()
{
	int data[] = {0, 9, 1, 2, 3};

	vector<int> arrayObj(data, data + sizeof(data) / sizeof(int));

	sort(arrayObj.begin(), arrayObj.end());

	PrintPermutation(arrayObj);

	return 0;
}