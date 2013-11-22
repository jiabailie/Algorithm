#include <cstdio>
#include <iostream>
#include <cstring>
#include <cassert>
#include <climits>

using namespace std;

int strToint(char* str)
{
    int i = 0;
    int flg = 1, ret = 0;

    /* whether the str is null or the length of the string is 0 */
    if(str == NULL || strlen(str) == 0)
    {
        cout << "the string is null." << endl;
        return 0;
    }
    
    int len = strlen(str);
    
    /* judge if the string has sign */
    if(str[0] == '-' || str[0] == '+')
    {
        i = 1;
        flg = str[0] == '-' ? -1 : 1;
    }
    for(; i < len; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            unsigned int p1 = ret * 10;
            unsigned int p2 = (unsigned int)(str[i] - '0');

            /* when a > 0 and b > 0, but a + b < 0, overflow happened */
            if(p1 + p2 > INT_MAX)
            {
                cout << "the number exceeds the limitation." << endl;
                return 0;
            }
            ret = p1 + p2;
        }
        else
        {
            cout << "there are illegal characters." << endl;
            return 0;
        }
    }

    return flg * ret;
}

int main()
{
    char str1[] = "";
    char str2[] = " ";
    char str3[] = "000";
    char str4[] = "-12";
    char str5[] = "345";
    char str6[] = "78&.";
    char str7[] = "1.23";
    char str8[] = "11111111111111111111";

    cout << strToint(str1) << endl << endl;
    cout << strToint(str2) << endl << endl;
    cout << strToint(str3) << endl << endl;
    cout << strToint(str4) << endl << endl;
    cout << strToint(str5) << endl << endl;
    cout << strToint(str6) << endl << endl;
    cout << strToint(str7) << endl << endl;
    cout << strToint(str8) << endl << endl;

    return 0;
}
