#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		int maxLen = 1;
		int longestBegin = 0;
		int n = s.length(), i = 0;
		int low = 0, high = 0;

		// One by one consider every character as center point of
		// even and odd length palindromes
		for(i = 1; i < n; ++i)
		{
			// Find the longest even length palindrome with
			// center points as i-1 and i.
			low = i - 1;
			high = i;
			while(low >= 0 && high < n && s[low] == s[high])
			{
				if(high - low + 1 > maxLen)
				{
					longestBegin = low;
					maxLen = high - low + 1;
				}
				--low;
				++high;
			}

			// Find the longest odd length palindrome with
			// center point as i.
			low = i - 1;
			high = i + 1;
			while(low >= 0 && high < n && s[low] == s[high])
			{
				if(high - low + 1 > maxLen)
				{
					longestBegin = low;
					maxLen = high - low + 1;
				}
				--low;
				++high;
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