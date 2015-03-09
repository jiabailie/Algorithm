#include <cstdio>
#include <iostream>

using namespace std;

int doubleSquare1(unsigned int m)
{
	int kind = 0;
	int i = 0, j = 0;
	unsigned int mvalue = 0;
	int ceiling = sqrt(m / 2.0);
	for(i = 0; i <= ceiling; ++i)
	{
		for(j = i; ; ++j)
		{
			mvalue = i * i + j * j;
			if(mvalue > m)
			{
				break;
			}
			else if(mvalue == m)
			{
				kind += 1;
			}
		}
	}

	return kind;
}

int doubleSquare2(unsigned int m)
{
	int kind = 0;
	int i = 0, j = 0;
	double k = 0;
	int ceiling = sqrt(m / 2.0);
	for(i = 0; i <= ceiling; ++i)
	{
		k = sqrt(m * 1.0 - i * i * 1.0);
		j = int(k);
		if(k * k - j * j * 1.0 <= 1e-10)
		{
			kind += 1;
		}
	}
	return kind;
}

int main()
{
	unsigned int m = 1215306625;
	cout << doubleSquare1(m) << endl;
	cout << doubleSquare2(m) << endl;

	return 0;
}