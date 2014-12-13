#include <cstdio>
#include <iostream>

using namespace std;

bool isPalindrome1(int x)
{
	if(x < 0)
	{
		return false;
	}
	int div = 1;
	int head = 0, tail = 0;
	while(x / div >= 10) { div *= 10; }
	while(div >= 10)
	{
		head = x / div;
		tail = x % 10;
		if(head != tail)
		{
			return false;
		}
		x = (x % div) / 10;
		div /= 100;
	}
	return true;
}

bool isPalindrome2(int x, int &y)
{
	if(x < 0) { return false; }
	if(x == 0) { return true; }
	if(isPalindrome2(x / 10, y) && (x % 10 == y % 10))
	{
		y /= 10;
		return true;
	}
	else
	{
		return false;
	}
}

bool isPalindrome2(int x)
{
	return isPalindrome2(x, x);
}
int main()
{
	int num = 0;
	bool res = false;
	cout << "Input a number:" << endl;
	while(cin >> num)
	{
		res = isPalindrome1(num);
		cout << (res ? "Yes" : "Not") << endl;
		res = isPalindrome2(num);
		cout << (res ? "Yes" : "Not") << endl;
	}
	return 0;
}