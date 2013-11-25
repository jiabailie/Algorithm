/*
 * References : www.codechef.com/problems/TLG/
 */
#include <cstdio>

using namespace std;

inline int scanInt()
{
	register int retInt = 0;
	register int d = 0;

	while((d = getchar()) >= '0')
	{
		// retInt = retInt * 10 + (d - '0') = retInt * (8 + 2) + (d - '0')
		//        = retInt * (2^3 + 2^1) + (d - '0')
		retInt = (retInt << 3) + (retInt << 1) + (d - '0');
	}

	return retInt;
}

inline void iabs(int a, int& v, int& i)
{
	v = a;
	i = 1;
	if(a < 0)
	{
		v = -a;
		i = 2;
	}
}

int main()
{
	int i = 0, c = 0;
	int s = 0, t = 0;
	int tm = 0, ti = 0;
	int rm = 0, ri = 0;

	c = scanInt();
	for(i = 1; i <= c; i++)
	{
		s += scanInt();
		t += scanInt();

		iabs(s - t, tm, ti);
		if(tm > rm)
		{
			rm = tm;
			ri = ti;
		}
	}

	printf("%d %d\n", ri, rm);

	return 0;
}
