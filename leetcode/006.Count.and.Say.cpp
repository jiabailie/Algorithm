#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string i2str(int count)
{
	string res("");
	int n = 1;
	while(count / n >= 10) { n *= 10; }
	while(n > 0)
	{
		res.push_back(char('0' + count / n));
		count %= n;
		n /= 10;
	}
	return res;
}

class Solution {
public:
    string countAndSay(int n) {
		if(n == 0) { return ""; }
		if(n == 1) { return "1"; }

		string res = "1";
		string s;
		int i = 0, j = 0;
		int len = 0, count = 0;
		for(i = 1; i < n; ++i)
		{
			len = res.size();
			for(j = 0; j < len; ++j)
			{
				count = 1;
				while((j + 1 < len) && (res[j] == res[j + 1]))
				{
					count += 1;
					j += 1;
				}
				s += i2str(count);
				s += res[j];
			}
			res = s;
			s.clear();
		}
		return res;
    }
};

int main()
{
	string str("1");
	int n = 0;
	Solution sol;

	while(cin >> n)
	{
		str = sol.countAndSay(n);
		cout << str.c_str() << endl;
	}
	return 0;
}