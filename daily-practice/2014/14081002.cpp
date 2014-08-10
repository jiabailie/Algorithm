/**
 * Reference: stackoverflow.com/questions/746082/how-to-find-list-of-possible-words-from-a-letter-matrix-boggle-solver
 *
 * You get a matrix of letters like so:
 * F X I E
 * A M L O
 * E W B X
 * A S T U
 * The goal of the game is to find as many words as you can that can be formed by chaining letters together. 
 * You can start with any letter, and all the letters that surround it are fair game, 
 * and then once you move on to the next letter, all the letters that surround that letter are fair game, 
 * except for any previously used letters. 
 * So in the grid above, for example, I could come up with the words LOB, TUX, SEA, FAME, etc. 
 * Words must be at least 3 characters, and no more than NxN characters, 
 * which would be 16 in this game but can vary in some implementations. 
 * While this game is fun and addictive, I am apparently not very good at it and I wanted to cheat a little bit 
 * by making a program that would give me the best possible words.
 */
#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
using namespace std;
const int n = 4;
const int m = 4;
bool visited[n][m];
char board[n][m] = 
{ 
	{'D', 'G', 'H', 'I'}, 
	{'K', 'L', 'P', 'S'},
	{'Y', 'E', 'U', 'T'},
	{'E', 'O', 'R', 'N'}
};
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
vector<string> dictionary;
int setPos(int x, int y) { return x * n + y; }
void getPos(int pos, int &x, int &y) { x = pos / n; y = pos % n; }
bool isPrefix(string str)
{
	int i = 0, j = 0;
	for(i = 0; i < dictionary.size(); ++i)
	{
		if(dictionary[i].size() < str.size())
		{
			continue;
		}
		for(j = 0; j < str.size(); ++j)
		{
			if(dictionary[i][j] != str[j])
			{
				break;
			}
		}
		if(j == str.size())
		{
			return true;
		}
	}
	return false;
}
bool isWord(string str)
{
	for(int i = 0; i < dictionary.size(); ++i)
	{
		if(strcmp(str.c_str(), dictionary[i].c_str()) == 0)
		{
			return true;
		}
	}
	return false;
}
void dfs(int x, int y, bool v[n][m], string strVisited)
{	
	if(isWord(strVisited))
	{
		cout << strVisited.c_str() << endl;
		return;
	}
	if(!isPrefix(strVisited))
	{
		return;
	}
	cout << strVisited.c_str() << endl;
	int i = 0;
	int tmpX = 0, tmpY = 0;
	for(i = 0; i < sizeof(dx) / sizeof(int); ++i)
	{
		tmpX = x + dx[i];
		tmpY = y + dy[i];
		if(tmpX >= 0 && tmpX < n && tmpY >= 0 && tmpY < m && !v[tmpX][tmpY])
		{
			v[tmpX][tmpY] = true;
			strVisited.push_back(board[tmpX][tmpY]);
			dfs(tmpX, tmpY, v, strVisited);
			v[tmpX][tmpY] = false;
			strVisited.pop_back();
		}
	}
}
int main()
{
	int i = 0, j = 0;
	string str;
	dictionary.push_back("IS");
	dictionary.push_back("SUPER");
	dictionary.push_back("KEY");
	dictionary.push_back("HLEP");
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < m; ++j)
		{
			visited[i][j] = true;
			str.push_back(board[i][j]);
			dfs(i, j, visited, str);
			visited[i][j] = false;
			str.pop_back();
		}
	}
	return 0;
}
