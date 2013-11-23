/*
we have walls of different heights. There is an array which is represented by an array of integers, 
where the value at each index is the height of the wall. 
Now imagine it rains. How much water is going to be accumulated in puddles between walls?

case [2, 5, 1, 2, 3, 4, 7, 7, 6] total volume : 10
case [2, 5, 1, 3, 1, 2, 1, 7, 7, 6] total volume : 17
case [6, 1, 4, 6, 7, 5, 1, 6, 4] total volume : 13

References: qandwhat.apps.runkite.com/i-failed-a-twitter-interview/
*/
#include <cstdio>
#include <iostream>

using namespace std;

int pool[] = {2, 5, 1, 3, 1, 2, 1, 7, 7, 6};

int solve()
{
	int ret = 0;
	int i = 0;
	int n = sizeof(pool) / sizeof(int);
	int left = 0;
	int right = n - 1;

	if(n < 3) { return 0; }
	while(left + 1 < right && pool[left] <= pool[left + 1]) { left++; }
	while(right - 1 > left && pool[right - 1] >= pool[right]) { right--; }

	while(left + 1 < right)
	{
		if(pool[left] <= pool[right])
		{
			for(i = left + 1; i < right && pool[i] <= pool[left]; i++)
			{
				ret += pool[left] - pool[i];
			}
			left = i;
		}
		else if(pool[left] > pool[right])
		{
			for(i = right - 1; i > left && pool[i] <= pool[right]; i--)
			{
				ret += pool[right] - pool[i];
			}
			right = i;		
		}
	}

	return ret;
}

int main()
{
	cout << solve() << endl;
	return 0;
}
