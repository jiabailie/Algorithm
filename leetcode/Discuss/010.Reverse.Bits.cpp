#include <cstdio>
#include <iostream>
#include <cassert>

using namespace std;

typedef unsigned int uint;

void printBits(uint x)
{
	char str[36];
	int i = 0, j = 0;
	memset(str, 0, sizeof(str));
	for(i = 31; i >= 0; --i)
	{
		str[j] = '0';
		if(x & (1u << i))
		{
			str[j] = '1';
		}
		j += 1;
	}
	cout << str << endl;
}

uint swapBits(int a, int b, uint x)
{
	int bitA = (x >> a) & 1;
	int bitB = (x >> b) & 1;
	if(bitA ^ bitB)
	{
		x ^= ((1u << a) | (1u << b));
	}
	return x;
}

uint reverseBits(uint x)
{
	int low = 0;
	int high = sizeof(x) * 8 - 1;

	while(low <= high)
	{
		x = swapBits(low, high, x);
		low += 1;
		high -= 1;
	}

	return x;
}

uint reverseBitsMask(uint x)
{
	assert(sizeof(x) == 4);
	x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
	x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
	x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
	x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
	x = ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16);
	return x;
}

int main()
{
	uint x = 32;
	while(cin >> x)
	{
		printBits(x);
		printBits(reverseBits(x));
		printBits(reverseBitsMask(x));
	}
	return 0;
}