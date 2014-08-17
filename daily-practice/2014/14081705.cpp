/**
 * There are two words a and b, you can three kinds of operations to transfer a to b. 
 * 1) delete a character, 2) replace a character with another, 3) insert a new character.
 * Please calculate the minimum edit distance of a and b.
 * eg. a = "kitten", b = "sitting".
 * You can do 1) replace: k -> s, 2) replace: e -> i, 3) insert: g.
 * Thus the result is 3.
 */
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxN = 100;
int dp[maxN][maxN];
inline int judge(char c1, char c2)
{
	return c1 == c2 ? 0 : 1;
}
inline int tmin(int a, int b, int c)
{
	return std::min(std::min(a, b), c);
}
int GetMinEditDistance(const char *str1, const char *str2)
{
	if(!str1 && !str2) { return 0; }
	if(str1 && !str2) { return strlen(str1); }
	if(!str1 && str2) { return strlen(str2); }

	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i = 0, j = 0;

	memset(dp, 0, sizeof(dp));

	for(i = 0; i < len1; ++i)
	{
		dp[0][i] = i;
	}
	for(i = 0; i < len2; ++i)
	{
		dp[i][0] = i;
	}
	for(i = 1; i <= len1; ++i)
	{
		for(j = 1; j <= len2; ++j)
		{
			dp[i][j] = tmin(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + judge(str1[i - 1], str2[j - 1]));
		}
	}

	return dp[len1][len2];
}
int main()
{
	char *str1 = "kitten";
	char *str2 = "sitting";

	cout << "str1 is " << str1 << endl;
	cout << "str2 is " << str2 << endl;

	cout << GetMinEditDistance(str1, str2) << endl;

	return 0;
}