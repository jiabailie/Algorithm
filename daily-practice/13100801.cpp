/* Implement an algorithm to print all possible valid combinations of braces when N pairs of paranthesis are given. 
 * Reference: http://www.careercup.com/question?id=5007980722388992
 */
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 3;

void filler(int cur, int numleft, int numright, char result[])
{
	if(cur == 2 * N)
	{
		result[2 * N] = '\0';
		cout << result << endl;
		return;
	}
	if(numleft > numright)
	{
		result[cur++] = ')';
		numright++;
		filler(cur, numleft, numright, result);
		numright--;
		cur--;
	}
	if(numleft < N)
	{
		result[cur++] = '(';
		numleft++;
		filler(cur, numleft, numright, result);
		numleft--;
		cur--;
	}
}

int main()
{
	char result[2 * N + 1];
	filler(0, 0, 0, result);

	return 0;
}
