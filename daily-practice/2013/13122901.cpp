#include <cstdio>
#include <iostream>
#include <climits>

using namespace std;

void solve(int t)
{
	int n = 0, i = 0, k = 0;
	int tspos = 0, tepos = 0;
	int spos = 0, epos = 0;
	int max = INT_MIN, tmp = 0;

	cin >> n;

	for(i = 0; i < n; i++)
	{
		cin >> k;
		tmp += k;

		if(tmp > max)
		{
			max = tmp;
			tepos = i;
			spos = tspos;
			epos = tepos;
		}
		if(tmp < 0)
		{
			tmp = 0;
			tspos = i + 1;
			tepos = i + 1;
		}
	}

	cout << "Case " << (t + 1) << ":" << endl;
	cout << max << " " << (spos + 1) << " " << (epos + 1) << endl;
}

int main()
{
	int n = 0;
	int i = 0;

	cin >> n;

	for(i = 0; i < n; i++)
	{
		solve(i);
		if(i < n - 1)
		{
			cout << endl;
		}
	}
}