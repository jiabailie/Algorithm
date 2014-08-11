#include <stdio.h>
#include <cstring>
#include <vector>
#include <iostream>
#include <map>
void displaySentence(std::map<int, char> &dictionary, std::vector<int> &words)
{
	for(std::vector<int>::iterator it = words.begin(); it != words.end(); ++it)
	{
		std::cout << dictionary[*it];
	}
	std::cout << std::endl;
}
bool splitSourceStr(int currPos, std::map<int, char> &dictionary, std::string &sourceStr, std::vector<int> &words)
{
	if(currPos == sourceStr.size())
	{
		displaySentence(dictionary, words);
		return true;
	}
	int iword = 0;
	std::string word;
	bool splitSuccess = false;
	for(int i = currPos; i < sourceStr.size(); ++i)
	{
		word.push_back(sourceStr[i]);
		iword = atoi(word.c_str());
		if(dictionary.find(iword) != dictionary.end())
		{
			words.push_back(iword);
			splitSuccess = splitSourceStr(i + 1, dictionary, sourceStr, words);
			words.pop_back();
		}
	}
	return splitSuccess;
}
void translateCode(std::map<int, char> &dictionary, std::string &sourceStr)
{
	std::vector<int> words;
	if(!splitSourceStr(0, dictionary, sourceStr, words))
	{
		std::cout << "The input string is illegal." << std::endl;
	}
}
int main()
{
	int i = 0;
	std::string sourceStr("12259");
	std::map<int, char> dictionary;
	for(i = 1; i <= 26; ++i)
	{
		dictionary[i] = char('a' + i - 1);
	}
	translateCode(dictionary, sourceStr);
	return 0;
}