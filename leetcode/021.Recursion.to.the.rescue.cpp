#include <cstdio>

using namespace std;

void putlong1(unsigned long n)
{
	unsigned long div = 1;
	unsigned long rem = 0;
	while(n / div > 10)
	{
		div *= 10;
	}
	while(div)
	{
		rem = n / div;
		putchar(char(rem + '0'));
		n %= div;
		div /= 10;
	}
}

void putlong2(unsigned long n)
{
	if(n < 10)
	{
		putchar(n + '0');
		return;
	}
	putlong2(n / 10);
	putchar(n % 10 + '0');
}

int main()
{
	unsigned long n = 10;

	while(scanf("%ul",&n) == 1)
	{
		putlong1(n);
		printf("\n");
		putlong2(n);
		printf("\n");
	}
	return 0;
}