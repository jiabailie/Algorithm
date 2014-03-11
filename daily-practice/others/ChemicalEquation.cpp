/**
 * Judge whether the chemical equation is balance.
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#define DEBUG

using namespace std;

vector<string> parsor(const char *fomula)
{
	string tmp;
	int i = 0;
	int len = strlen(fomula);
	vector<string> token;

	for(i = 0; i < len; ++i)
	{
		if(fomula[i] == ' ')
		{
			continue;
		}
		else if(fomula[i] == '+' || fomula[i] == '=')
		{
			token.push_back(string(tmp.begin(), tmp.end()));
			token.push_back(string(1, fomula[i]));

			tmp.clear();
		}
		else if(fomula[i] >= 'A' && fomula[i] <= 'Z')
		{
			if(tmp.size() == 0)
			{
				token.push_back(string("1"));
			}
			else
			{
				token.push_back(string(tmp.begin(), tmp.end()));
				tmp.clear();
			}
			tmp.push_back(fomula[i]);
		}
		else if(fomula[i] >= 'a' && fomula[i] <= 'z')
		{
			tmp.push_back(fomula[i]);
		}
		else if(fomula[i] >= '0' && fomula[i] <= '9')
		{
			if(tmp.size() == 0)
			{
				tmp.push_back(fomula[i]);
			}
			else
			{
				if(!(tmp.back() >= '0' && tmp.back() <= '9'))
				{
					token.push_back(string(tmp.begin(), tmp.end()));
					tmp.clear();
				}
				tmp.push_back(fomula[i]);
			}
		}
	}

	token.push_back(string(tmp.begin(), tmp.end()));

	return token;
}

map<string, int> calcone(vector<string> &elem)
{
	int i = 0;
	int len = int(elem.size());
	int mul = atoi(elem[0].c_str());
	map<string, int> temp;

	for(i = 1; i < len; ++i)
	{
		if(elem[i][0] >= 'A' && elem[i][0] <= 'Z')
		{			
			if(i + 1 < len && elem[i + 1][0] >= '0' && elem[i + 1][0] <= '9')
			{
				temp[elem[i]] = atoi(elem[i + 1].c_str()) * mul;
				i = i + 1;
			}
			else
			{
				temp[elem[i]] = mul;
			}
		}
	}

	return temp;
}

void addelem(map<string, int> &source, map<string, int> &destin)
{
	for(map<string, int>::iterator it = source.begin(); it != source.end(); ++it)
	{
		string tmp = string(it->first.begin(), it->first.end());
		if(destin.find(tmp) != destin.end())
		{
			destin[tmp] += it->second;
		}
		else
		{
			destin[tmp] = it->second;
		}
	}
}

map<string, int> calc(vector<string> &part)
{
	int i = 0, j = 0;
	int len = int(part.size());
	vector<string> elem;
	map<string, int> elems;
	map<string, int> temp;

	for(i = 0; i < len; )
	{
		elem.clear();
		temp.clear();
		for(j = i; ; ++j)
		{
			if(j == len || part[j][0] == '+')
			{
				i = j + 1;
				break;
			}
			elem.push_back(string(part[j].begin(), part[j].end()));
		}
		temp = calcone(elem);
		addelem(temp, elems);
	}

	return elems;
}

bool isbalance(const char *fomula)
{
	int i = 0, p = 0;
	int status = 0; // 0 number, 1 character

	string tmp;
	vector<string> separate = parsor(fomula);
	vector<string> prepart;
	vector<string> pospart;

	for(vector<string>::iterator it = separate.begin(); it != separate.end(); ++it)
	{
		if((*it)[0] == '=')
		{
			p = 1;
			continue;
		}
		if(p == 0)
		{
			prepart.push_back(*it);
		}
		else
		{
			pospart.push_back(*it);
		}
	}
	map<string, int> premap = calc(prepart);
	map<string, int> posmap = calc(pospart);

	for(map<string, int>::iterator it = premap.begin(); it != premap.end(); ++it)
	{
		if(posmap.find(it->first) == posmap.end() || posmap[it->first] != it->second)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	string line("H2 + O2 = H2O");//("Cu + CuS = Cu2S");
#ifndef DEBUG
	while(getline(cin, line), line.size() > 0)
	{
#endif
		bool f = isbalance(line.c_str());
#ifndef DEBUG
	}
#endif

	return 0;
}