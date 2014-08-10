/**
 * Find the first character, which appears only once in the given sentence.
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<char, int> statisPos;
char firstOnlyAppearOnceCharacter(const char *content)
{
	if(!content) { return 0; }
	int i = 0;
	int minPos = 0;
	char minCha = 0;

	statisPos.clear();
	for(i = 0; i < strlen(content); ++i)
	{
		if(statisPos.find(content[i]) == statisPos.end())
		{
			statisPos[content[i]] = i;
		}
		else
		{
			statisPos[content[i]] = strlen(content);
		}
	}
	if(statisPos.size() == 0) { return 0; }
	minPos = statisPos.begin()->first;
	minCha = statisPos.begin()->second;
	for(map<char, int>::iterator it = statisPos.begin(); it != statisPos.end(); ++it)
	{
		if(it->second < minPos)
		{
			minPos = it->second;
			minCha = it->first;
		}
	}
	return minCha;
}
char firstOnlyAppearOnceCharacterGeneral(const char *content)
{
	if(!content) { return 0; }
	int i = 0, j = 0;
	int statis[256];
	vector<char> appearOnce;
	memset(statis, 0, sizeof(statis));
	for(i = 0; i < strlen(content); ++i)
	{
		statis[int(content[i])] += 1;
	}
	for(i = 0; i < 256; ++i)
	{
		if(statis[i] == 1)
		{
			appearOnce.push_back(char(i));
		}
	}
	if(appearOnce.size() == 0)
	{
		return 0;
	}
	for(i = 0; i < strlen(content); ++i)
	{
		for(j = 0; j < appearOnce.size(); ++j)
		{
			if(content[i] == appearOnce[j])
			{
				return content[i];
			}
		}
	}
	return 0;
}
int main()
{
	char content[] = "this is a character, which is the first ever appearing once in the sentence.";

	cout << firstOnlyAppearOnceCharacter(content) << endl;
	cout << firstOnlyAppearOnceCharacterGeneral(content) << endl;
	return 0;
}