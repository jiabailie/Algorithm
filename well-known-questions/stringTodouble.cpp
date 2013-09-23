#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

const int LEN = 100;

inline double iatof(char ary[])
{
	if(!ary || strlen(ary) == 0)
	{
		return INT_MIN;
	}

	int i = 0, j = 0;
	int len = strlen(ary);
	int dot = 0;
	int sign = 1;
	double part1 = 0.0;
	double part2 = 0.0;

	if(ary[0] == '-' || ary[0] == '+')
	{
		sign = ary[0] == '-' ? -1 : 1;
		i++;
	}

	for(; i < len; i++)
	{
		if(ary[i] == '.')
		{
			dot++;
			break;
		}
		if(ary[i] < '0' || ary[i] > '9')
		{
			cout << "The input string is illegal, please input again." << endl;
			return INT_MIN;
		}
		part1 = part1 * 10 + int(ary[i] - '0');
	}
	if(dot == 1)
	{
		for(j = len - 1; j > i; j--)
		{
			if(ary[j] < '0' || ary[j] > '9')
			{
				cout << "The input string is illegal, please input again." << endl;
				return INT_MIN;
			}
			part2 = part2 * 0.1 + int(ary[j] - '0') * 0.1;
		}
	}

	return sign * (part1 + part2);
}

int main()
{
	char ary[LEN];

	cin >> ary;

	double x = atof(ary);

	cout << x << endl;

	cout << iatof(ary) << endl;

	return 0;
}
