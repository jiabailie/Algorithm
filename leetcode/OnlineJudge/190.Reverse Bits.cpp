#include <cstdio>
#include <vector>
#include "lib\common.h"

typedef unsigned int uint32_t;

using namespace std;

class Solution {
public:
	uint32_t swapBits(uint32_t n, int p1, int p2)
	{
		if(((n >> p1) & 1) ^ ((n >> p2) & 1))
		{
			n ^= ((1u << p1) | (1u << p2));
		}
		return n;
	}
    uint32_t reverseBits(uint32_t n) 
	{
        int p1 = 31;
		int p2 = 0;
		
		// if the highest position is not 32, find it.
		// for(p1 = 0; p1 <= 32 && (1u << (p1 + 1)) < n; ++p1);

		while(p1 > p2)
		{
			n = swapBits(n, p1, p2);
			p1 -= 1;
			p2 += 1;
		}

		return n;
    }
};

void displayBinary(uint32_t num)
{
	vector<int> binary;
	while(num)
	{
		if(num & 1)
		{
			binary.push_back(1);
		}
		else
		{
			binary.push_back(0);
		}
		num >>= 1;
	}
	for(int i = binary.size() - 1; i >= 0; --i)
	{
		cout << binary[i];
	}
	cout << endl;
}

int main()
{
	Solution sol;

	uint32_t num = 1;
	displayBinary(num);

	uint32_t res = sol.reverseBits(num);
	displayBinary(res);

	return 0;
}