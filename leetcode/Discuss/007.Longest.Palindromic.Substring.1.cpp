#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

bool dp[1000][1000] = {false};

class Solution {
public:
    string longestPalindrome(string s) {
		int n = s.length();
		int longestBegin = 0;
		int maxLen = 1;
		int i = 0, j = 0, k = 0;
		memset(dp, 0, sizeof(dp));
		for(i = 0; i < n; ++i)
		{
			dp[i][i] = true;
		}
		for(i = 0; i < n - 1; ++i)
		{
			if(s[i] == s[i + 1])
			{
				dp[i][i + 1] = true;
				longestBegin = i;
				maxLen = 2;
			}
		}
		for(k = 3; k <= n; ++k)
		{
			for(i = 0; i < n - k + 1; ++i)
			{
				j = i + k - 1;
				if(s[i] == s[j] && dp[i + 1][j - 1])
				{
					dp[i][j] = true;
					longestBegin = i;
					maxLen = k;
				}
			}
		}
		return s.substr(longestBegin, maxLen);
    }
};

int main()
{
	Solution sol;
	string l = sol.longestPalindrome(string("aaabaaaa"));
	cout << l.c_str() << endl;
	return 0;
}