#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <vld.h>

using namespace std;

char nextChar(map<char, int> &map_Amount)
{
	char c_Ret = 0;
	int i_Max = 0;
	for(map<char, int>::iterator it = map_Amount.begin(); it != map_Amount.end(); ++it)
	{
		if(it->second > i_Max)
		{
			c_Ret = it->first;
			i_Max = it->second;
		}
	}
	return c_Ret;
}

char* create(char* str, int d)
{
	if(!str || strlen(str) == 0)
	{
		return 0;
	}
	int i = 0;
	int i_Len = strlen(str);
	char* p_Ret = new char[i_Len + 1];
	memcpy(p_Ret, str, i_Len + 1);

	map<char, int> map_Amount;

	for(i = 0; i < i_Len; ++i)
	{
		if(map_Amount.find(str[i]) == map_Amount.end())
		{
			map_Amount[str[i]] = 0;
		}
		map_Amount[str[i]] += 1;
	}	

	if(d == 0)
	{
		return p_Ret;
	}

	int i_Pos = 0;
	char c_Next = 0;
	memset(p_Ret, 0, sizeof(char) * (i_Len + 1));
	while((c_Next = nextChar(map_Amount)) != 0)
	{
		i_Pos = 0;		
		while(map_Amount[c_Next] > 0 && i_Pos < i_Len)
		{
			while(p_Ret[i_Pos])
			{
				i_Pos += 1;
			}
			p_Ret[i_Pos] = c_Next;
			map_Amount[c_Next] -= 1;
			i_Pos += d;
		}
		if(map_Amount[c_Next] > 0) // can not finish the task
		{
			delete p_Ret;
			return 0;
		}
	}

	return p_Ret;
}

int main()
{
	char* str = "abb";
	int d = 2;
	char* ord = create(str, d);

	cout << ord << endl;

	if(d > 0 && ord)
	{
		delete ord;
	}
	return 0;
}