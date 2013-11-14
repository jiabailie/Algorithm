#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

inline void BestCowLine(vector<char>& cows)
{
	int l = 1, i = 0, j = 0, t = 0;
	int s = 0, e = cows.size() - 1;

	while(s <= e)
	{
		l = 1;
		t++;
		for(i = s, j = e; i <= j ; i++, j--)
		{
			if(cows[i] < cows[j]) { l = 1; break; }
			else if(cows[i] > cows[j]) { l = 0; break; }
		}
		if(l)
		{
			cout << cows[s];
			s++;
		}
		else
		{
			cout << cows[e];
			e--;
		}
		if(t % 80 == 0)
		{
			cout << endl;
		}
	}
}

int main()
{
	char t;
	int n = 0;
	int i = 0;
	vector<char> line;

	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> t;
		line.push_back(t);
	}

	BestCowLine(line);

	cout << endl;

	return 0;
}