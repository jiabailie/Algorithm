#include <cstdio>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        if(!str || strlen(str) == 0)
		{
			return 0;
		}
		int p = 0;
		long long sign = 1;
		long long res = 0;
		while(str[p] == ' ' && p < strlen(str)) { p += 1; }
		if(p == strlen(str)) { return 0; }
		if(str[p] == '-') 
		{ 
			sign = -1;
			p += 1; 
		}
		else if(str[p] == '+') 
		{ 
			sign = 1; 
			p += 1; 
		}
		for(int i = p; i < strlen(str) && str[i] != ' '; ++i)
		{
			if(str[i] < '0' || str[i] > '9')
			{
				break;
			}
			res = res * 10 + (str[i] - '0');			
			if(res * sign > INT_MAX)
			{
				return INT_MAX;
			}
			else if(res * sign < INT_MIN)
			{
				return INT_MIN;
			}
		}
		return res * sign;
    }
};

int main()
{
	char str[] = "9223372036854775809";

	Solution sol;

	cout << sol.atoi(str) << endl;

	return 0;
}