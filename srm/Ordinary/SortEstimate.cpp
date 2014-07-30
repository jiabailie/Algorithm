#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

class SortEstimate
{
public:
	double howMany(int c, int time);
};

double SortEstimate::howMany(int c, int time)
{
	int i = 0;
	double rhValue = time * log(2.0) / (c * 1.0);
	double tmp = 0.0, startN = 1, endN = 1, midN = 1;

	while(endN * log(endN) - rhValue < 1e-9)
	{
		endN = endN * 2.0;
	}

	for(i = 0; i < 10000; ++i)
	{
		midN = startN + (endN - startN) * 0.5;
		tmp = midN * log(midN) - rhValue;
		if(tmp < -1e-9)
		{
			startN = midN;	
		}
		else if(tmp > 1e-9)
		{
			endN = midN;
		}
	}
	return midN;
}