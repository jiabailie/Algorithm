#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
		if(*p == 0)
		{
			return *s == 0;
		}

		// if next char is not '*', must match current character
		if(*(p + 1) != '*')
		{
			return ((*p == *s) || (*p == '.' && *s != 0)) && isMatch(s + 1, p + 1);
		}

		// if next char is '*'
		while((*p == *s) || (*p == '.' && *s != 0))
		{
			if(isMatch(s, p + 2))
			{
				return true;
			}
			s += 1;
		}
		return isMatch(s, p + 2);
    }
};

int main()
{
	Solution sol;
	bool res[7] = {false};
	res[0] = sol.isMatch("aa","a");
	res[1] = sol.isMatch("aa","aa");
	res[2] = sol.isMatch("aaa","aa");
	res[3] = sol.isMatch("aa", "a*");
	res[4] = sol.isMatch("aa", ".*");
	res[5] = sol.isMatch("ab", ".*");
	res[6] = sol.isMatch("aab", "c*a*b");
	for(int i = 0; i < 7; ++i)
	{
		cout << (res[i] ? 1 : 0) << endl;
	}
	return 0;
}