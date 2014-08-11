/**
 * There is a string and a char set, finding the shortest sub-string which contains all kinds of characters of given char set.
 * Reference: blog.csdn.net/haipeng31/article/details/8186432
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
bool FindStartEnd(int &start, int &end, map<char, int> &charLastPos)
{
	start = 0x7ffff;
	end = -1;
	for(map<char, int>::iterator it = charLastPos.begin(); it != charLastPos.end(); ++it)
	{
		if(it->second == -1)
		{
			return false;
		}
		start = it->second < start ? it->second : start;
		end = it->second > end ? it->second : end;
	}
	return true;
}
string FindShortestSubSet(string &charSet, string &str)
{
	int i = 0, j = 0;
	int minLen = 0x7fff;
	int start = 0, end = 0;
	string res;
	map<char, int> charLastPos;
	for(i = 0; i < charSet.length(); ++i)
	{
		charLastPos[charSet[i]] = -1;
	}
	for(i = 0; i < str.length(); ++i)
	{
		if(charLastPos.find(str[i]) != charLastPos.end())
		{
			charLastPos[str[i]] = i;
			if(FindStartEnd(start, end, charLastPos))
			{
				if(end - start + 1 < minLen)
				{
					minLen = end - start + 1;
					res.clear();
					for(j = start; j <= end; ++j)
					{
						res.push_back(str[j]);
					}
				}
			}
		}
	}
	return res;
}
int main()
{
	string charSet("abcd");
	string str("aaaaaaaaaacbebbbbbdddddddcccccc");

	string res = FindShortestSubSet(charSet, str);

	cout << res.c_str() << endl;

	return 0;
}
