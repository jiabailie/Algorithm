/* Using Babylonian Method and Binary Search to computing square roots. */
#include <cstdio>
#include <cstring>
#include <vector>
#include <iomanip>
#include <climits>
#include <algorithm>
#include <cmath>
#include <iostream>

const double delta = 1e-16;

const int TIMES = 1000;

using namespace std;

template<typename T>
inline T iABS(T v) { return v < 0 ? -v : v; }

template<typename T, typename U>
inline T calPow(T base, U power)
{
	/* 0 can't be divisor. */
	if(iABS(base) - 0 < delta && power < 0)
	{
		cout << "The base can't be 0." << endl;
		return INT_MIN;
	}

	T sign = 1;
	T flip = 1;	

	/* If power == 0, the result should be 1. */
	if(iABS(power) - 0 < delta) { return sign * 1; }

	/* If base is negative and power is odd number, the sign should be -1. */
	if(base < 0 && (power & 1))
	{
		sign = -1;
		base = iABS(base);
	}
	if(power < 0)
	{
		flip = 0;
		power = iABS(power);
	}
	
	if(power == 1) { return sign * (flip ? base : 1 / (base * 1.0)); }

	T ret = calPow(base, power >> 1);
	ret = ret * ret;
	if(power & 1)
	{
		ret = base * ret;
	}

	/* If the power is negative number, flip the number. */
	if(!flip)
	{
		ret = 1 / (ret * 1.0);
	}
	return sign * ret;
}

/* Using Rough estimation to get the approximation. */
inline double RoughEstimation(double value)
{
	int p = 0;
	while(value - 100 >delta)
	{
		value = value / 100;
		p++;
	}
	return (value >= 10 ? 6 : 2) * calPow(10, p);
}

/* Do iteration TIMES times, to get the value. */
inline double BabylonianMethod(double source)
{
	if(source <= 0)
	{
		cout << "The input number is not positive number." << endl;
		return INT_MIN;
	}
	double rough = RoughEstimation(source);
	double pre = rough;
	for(int i = 0; i < TIMES; i++)
	{
		pre = rough;
		rough = (rough + source * 1.0 / rough) * 0.5;
		if(iABS(pre - rough) < delta)
		{
			break;
		}
	}
	return rough;
}

/* Using binary search to find the sqrt root. */
inline double BinarySearchSquareRoot(double source)
{
	if(source <= 0)
	{
		cout << "The input number is not positive number." << endl;
		return INT_MIN;
	}
	double start = 0;
	double end = source;
	double mid = source * 0.5;

	for(int i = 0; i < TIMES; i++)
	{
		double tmp = mid * mid;
		double pre = mid;
		if(tmp > source)
		{
			end = mid;
		}
		if(tmp < source)
		{
			start = mid;
		}
		mid = start + (end - start) * 0.5;
		if(iABS(pre - mid) < delta)
		{
			break;
		}
	}
	return mid;
}

int main()
{
	for(int i = 0; i < 100; i++)
	{
		double source = rand() % 1000;
		double root1 = BabylonianMethod(source);
		double root2 = BinarySearchSquareRoot(source);
		double root3 = sqrt(source);
	}

	return 0;
}
