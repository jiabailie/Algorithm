#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

char letter[30];
char sentence[150010];

inline void solve()
{
	int cnt[26];
	int i = 0, j = 25;
	map<int, vector<char> > dic;
	map<char, char> code;
	
	gets(letter);

	gets(sentence);

	memset(cnt, 0, sizeof(cnt));
	for(i = 0; i < strlen(sentence); i++)
	{
		if(sentence[i] >= 'a' && sentence[i] <= 'z')
		{
			cnt[(sentence[i] - 'a')]++;
		}
		else if(sentence[i] >= 'A' && sentence[i] <= 'Z')
		{
			cnt[(sentence[i] - 'A')]++;
		}
	}

	for(i = 0; i < 26; i++)
	{
		if(cnt[i] > 0)
		{
			dic[cnt[i]].push_back(char('a' + i));
		}
	}

	for(map<int, vector<char> >::reverse_iterator it = dic.rbegin(); it != dic.rend(); it++)
	{
		for(vector<char>::reverse_iterator iit = it->second.rbegin(); iit != it->second.rend(); iit++)
		{
			code[(*iit)] = letter[j--];
		}
	}

	for(i = 0; i < strlen(sentence); i++)
	{
		if(sentence[i] >= 'a' && sentence[i] <= 'z')
		{
			sentence[i] = code[sentence[i]];
		}
		else if(sentence[i] >= 'A' && sentence[i] <= 'Z')
		{
			sentence[i] = code[(sentence[i] - 'A' + 'a')] - 'a' + 'A';
		}
	}

	printf("%s\n", sentence);
}

int main()
{
	int t = 0;
	int i = 0;

	scanf("%d", &t);
	getchar();
	for(i = 0; i < t; i++)
	{
		solve();
	}
	return 0;
}
