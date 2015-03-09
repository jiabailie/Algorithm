#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;
		unsigned int m = (1 << 31) - 1;
		long long ret = 0;
		x *= sign;
		while(x > 0)
		{
			ret = ret * 10 + (x % 10);
			x /= 10;
		}
		if(ret > m)
		{
			ret = 0;
		}
		return (ret * sign);
    }
};

int main()
{
	int x = 0;
	Solution sol;
	while(cin >> x)
	{
		cout << sol.reverse(x) << endl;
	}
	return 0;
}