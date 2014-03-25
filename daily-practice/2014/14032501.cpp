/**
 * From: www.careercup.com/question?id=5642266903314432
Description:
Given a mapping configuration such as: 

1:a 
2:b 
... 
26:z 

And a string like "12632", print the number of different ways you can map such string to alphabet characters. 
For example, given "111" the answer is 3 because you can make "aaa", "ak" and "ka" different mappings. 
However, given "101" the answer is 1 because you can only make "ja" as a possible mapping (01 is not valid).
 */
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#define DEBUG
#undef  DEBUG

using namespace std;

map<int, char> dic;

bool judgeValid(string code)
{
	if(code.size() > 1 && code[0] == '0')
	{
		return false;
	}

	int num = atoi(code.c_str());

	if(dic.find(num) != dic.end())
	{
		return true;
	}
	return false;
}

char getValue(string code)
{
	int num = atoi(code.c_str());
	return dic[num];
}

void printCode(int cur, vector<char> dcode, string source)
{
	if(cur == source.size())
	{
		for(vector<char>::iterator it = dcode.begin(); it != dcode.end(); ++it)
		{
			cout << (*it);
		}
		cout << endl;

		return;
	}
	
	string tmp;
	for(int i = cur; i < source.size(); ++i)
	{
		tmp.push_back(source[i]);
		if(judgeValid(tmp))
		{
			dcode.push_back(getValue(tmp));
			printCode(i + 1, dcode, source);
			dcode.pop_back();
		}
	}
}

#ifdef DEBUG
void testMap()
{
	for(map<int, char>::iterator it = dic.begin(); it != dic.end(); ++it)
	{
		cout << it->first << ", " << it->second << endl;
	}
}

void testJudgeValid()
{
	bool tmp;
	vector<string> tvec;
	tvec.push_back(string("10"));
	tvec.push_back(string("16"));
	tvec.push_back(string("30"));
	tvec.push_back(string("01"));
	tvec.push_back(string("00"));
	tvec.push_back(string("8"));

	for(vector<string>::iterator it = tvec.begin(); it != tvec.end(); ++it)
	{
		tmp = judgeValid(*it);
		cout << (tmp ? "True" : "False") << endl;
	}
}
#endif

void testPrintCode()
{
	vector<string> tvec;
	tvec.push_back("12632");
	tvec.push_back("111");
	tvec.push_back("101");
	for(vector<string>::iterator it = tvec.begin(); it != tvec.end(); ++it)
	{
		cout << "Test " << (*it).c_str() << ":" << endl;
		printCode(0, vector<char>(), *it);
		cout << endl;
	}
}

int main()
{
	int i = 0;
	for(i = 1; i <= 26; ++i)
	{
		dic[i] = char('a' + i - 1);
	}

#ifdef DEBUG
	testMap();
	testJudgeValid();	
#endif
	testPrintCode();
	return 0;
}