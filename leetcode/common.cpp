#include "common.h"

const int n = 17;
const int mod = 20;

void iswap(int &a, int &b) { int c = a; a = b; b = c; }

void makeArray(std::vector<int> &sortAry)
{
	for(int i = 0; i < n; ++i)
	{
		sortAry.push_back(rand() % mod);
	}
}

void displayArray(std::vector<int> &sortAry)
{
	for(size_t i = 0; i < sortAry.size(); ++i)
	{
		std::cout << sortAry[i] << " ";
	}
	std::cout << std::endl << std::endl;
}

void displaySortArray(std::vector<int> &sortAry)
{
	std::vector<int> cpyAry(sortAry.begin(), sortAry.end());
	std::sort(cpyAry.begin(), cpyAry.end());
	displayArray(cpyAry);
}

// whether the next char is splitting token
bool isToken(char c, std::string &token)
{
	for(std::string::iterator it = token.begin(); it != token.end(); ++it)
	{
		if(c == (*it))
		{
			return true;
		}
	}
	return false;
}

// whether the next word is number or not
bool isNumber(std::string &str)
{
	if(str.size() == 0)
	{
		return false;
	}
	for(size_t i = 0; i < str.size(); ++i)
	{
		if(str[i] < '0' || str[i] > '9')
		{
			return false;
		}
	}
	return true;
}

// transfer a string to integer
int str2int(std::string &str)
{
	int ret = 0;
	for(size_t i = 0; i < str.size(); ++i)
	{
		ret = ret * 10 + (str[i] - '0');
	}
	return ret;
}

// read text from file
std::vector<std::string> readFile(std::ifstream &in, std::string &token)
{
	if(!in.is_open())
	{
		std::cout << "Error during opening the file." << std::endl;
		exit(1);
	}
	char c;
	std::string word;
	std::vector<std::string> vec_Str;
	while(in.get(c))
	{
		if(!isToken(c, token))
		{
			word.push_back(c);
			continue;
		}

		if(word.length() > 0)
		{
			vec_Str.push_back(std::string(word.begin(), word.end()));
			word.clear();
		}
	}
	if(word.length() > 0)
	{
		vec_Str.push_back(std::string(word.begin(), word.end()));
	}

	return vec_Str;
}