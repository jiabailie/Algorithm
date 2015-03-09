#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

string int2str(int n, int b)
{
	string str(1, 'a' + n % b);
	n /= b;
	while(n != 0)
	{
		str.push_back(char('a' + (n - 1) % 26));
		n = (n - 1) / 26;
	}
	return str;
}

string reverseStr(string a)
{
	char c = 0;
	int i = 0;
	int j = a.size() - 1;
	while(i < j)
	{
		c = a[i];
		a[i] = a[j];
		a[j] = c;
		i += 1;
		j -= 1;
	}
	return a;
}

int main()
{
	int n = 0;

	for(n = 0; n <= 100; ++n)
	{
		string str = reverseStr(int2str(n, 26));
		cout << n << "\t" << str.c_str() << endl;
	}

	return 0;
}