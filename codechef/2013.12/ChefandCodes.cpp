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
	int cnt[256];
	int i = 0, j = 25;
	map<int, vector<char> > dic;
	map<char, char> code;
	
	gets(letter);

	gets(sentence);

	memset(cnt, 0, sizeof(cnt));
	for(i = 0; i < strlen(sentence); i++) 
	{ 
		cnt[sentence[i]]++; 
	}
	for(i = 0; i < 256; i++)
	{
		if(cnt[i] > 0) 
		{ 
			code[i] = i; 
		}
	}

	for(i = 0; i < 26; i++) 
	{ 
		cnt[i] = cnt['a' + i] + cnt['A' + i]; 
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
			code[(*iit) - 'a' + 'A'] = code[(*iit)] - 'a' + 'A';
		}
	}

	for(i = 0; i < strlen(sentence); i++)
	{
		printf("%c", code[sentence[i]]);
	}

	printf("\n");
}

int main()
{
	int t = 0;
	int i = 0;

	unsigned char c[258];
	for(i = 0; i < 258; i++)
	{
		c[i] = i;
	}

	scanf("%d", &t);
	getchar();
	for(i = 0; i < t; i++)
	{
		solve();
	}
	return 0;
}
