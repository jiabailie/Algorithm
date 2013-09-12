/*
 * You're given 50 cups of sugar water. Each cup has the same volume but different amount sugar in it. 
 * Each cup is labeled with the ratio. Write an algorithm that tells us if it is possible to  
 * mix together different cups and get sugar water with perfect 1:1 ratio
 */
#define GENERATE_RANDOM_NUMBER
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int r = 5;
const int n = 50;
int V = 0;
vector<int> C;

double function1(double seed) { return abs(11 * ((abs(cos(log(seed * seed + 17.1 * seed * log(453.1) + 13.7) / log(3.0) * 13657) / 83) * 10703 + 1.7) / 0.3713571) * 10) + 3; }
double function2(double seed) { return abs(17 * ((abs(cos(log(seed * seed + 19.7 * seed * log(697.3) + 17.9) / log(7.0) * 17757) / 89) * 13503 + 1.9) / 0.7415923) * 10) + 7; }
double function3(double seed) { return abs(19 * ((abs(cos(log(seed * seed + 23.3 * seed * log(799.7) + 23.7) / log(9.0) * 19357) / 91) * 17513 + 3.3) / 0.9415923) * 10) + 11; }
double function4(double seed) { return 23 * (log(function1(seed) * function2(seed) * 13 + function3(seed) * 7) + 1.7) / 0.137237; }
double function5(double seed) { return 29 * (log(function1(seed) * function3(seed) * 19 + function2(seed) * 73) + 1.97) / 0.137237; }

/* Generate the array to test the program. */
inline void generateRandomArray()
{
	int i = 0, max = 0;
#ifdef GENERATE_RANDOM_NUMBER
	double (*random[r])(double) = {function1, function2, function3, function4, function5};
	for(i = 0; i < n; i++)
	{
		C.push_back(int(random[(i * 3 % r)](i * 1.0)));
		if(C[i] > max) { max = C[i]; }
	}
	for(i = 0; i < n; i++)
	{
		C[i] = int(C[i] * V / max);
	}
#else
	for(i = 0; i < n; i++)
	{
		C.push_back(rand() % (V + 1));
	}
#endif
}

/* One step of this recursion. */
inline bool oneStep(int cur, int cnt, int countV, int curSum, vector<int>& result)
{
	/* If countV items have been put into the pool, and the water sugar ratio is 1:1.  */
	if(cnt == countV && curSum == (countV * V) / 2)
	{
		return true;
	}
	/* If the search has to the end of the array and the water sugar ratio is not 1:1. */
	if((cnt >= countV || cur == n - 1) && curSum != (countV * V) / 2)
	{
		return false;
	}
	bool ret = false;
	for(int i = cur + 1; i < n && !ret; i++)
	{
		result.push_back(C[i]);
		ret |= oneStep(i + 1, cnt + 1, countV, curSum + C[i], result);
		if(!ret)
		{
			result.pop_back();
		}
	}
	return ret;
}

/* The main branch to deal with the process. */
inline bool mixWater(int countV, vector<int>& result)
{
	bool ret = false;
	for(int i = 0; i < n && !ret; i++)
	{
		result.clear();
		result.push_back(C[i]);
		ret |= oneStep(i, 1, countV, C[i], result);
	}
	return ret;
}

int main()
{
	bool success = false;
	vector<int> result;
	cin >> V;
	generateRandomArray();
	sort(C.begin(), C.end());

	for(int i = 1; i <= n && !success; i++)
	{
		result.clear();
		if(((i * V) & 1) == 0)
		{
			success = mixWater(i, result);
		}
	}

	if(success)
	{
		for(vector<int>::iterator it = result.begin(); it != result.end(); it++)
		{
			cout << (*it) << " ";
		}
		cout << endl;
	}

	return 0;
}
