#include <stdio.h>
#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

const int MAX = 10010;
const ll MOD = 1000000007;

char str[MAX];

class Test {
public:
    static int howmany (string s)
    {
		ll ret = 0;
		int i = 0, j = 0;
		int n = s.length();

		ll dic[26];
		char next[26];

		memset(dic, 0, sizeof(dic));

		strcpy(str, s.c_str());

		next['b' - 'a'] = 'i';
		next['i' - 'a'] = 'n';
		next['n' - 'a'] = 'g';
		
		for(i = n - 1; i >= 0; i--)
		{
			if(str[i] == 'g')
			{
				dic['g' - 'a'] = (dic['g' - 'a'] + 1) % MOD;
			}
			else
			{
				dic[str[i] - 'a'] = (dic[str[i] - 'a'] + dic[next[str[i] - 'a'] - 'a']) % MOD;
			}
		}

		return int(dic['b' - 'a'] % MOD);
    }
};
//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{   
    cout<<Test::howmany("iinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbingiinbinbing")<<endl;   
} 
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。