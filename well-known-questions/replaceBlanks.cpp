#include <cstdio>
#include <iostream>

using namespace std;

const int MAX = 100;

/* replace blanks with %20 */
void replaceBlanks(int length, char str[])
{
    /* if the input string is illegal */
    if(str == NULL || length <= 0)
    {
        return;
    }

    int i = 0;
    int blanks = 0; /* the number of blanks in str */
    int original = 0; /* the total length of str */

    for(i = 0; str[i] != '\0'; i++)
    {
        original++;
        if(str[i] == ' ')
        {
            blanks++;
        }
    }

    int newlen = original + 2 * blanks;
    /* if the new length is larger than str's maximum length after replace all blanks with %20*/
    if(newlen > length)
    {
        return;
    }

    int indexOriginal = original;
    int indexNew = newlen;

    while(indexOriginal >= 0 && indexNew > indexOriginal)
    {
        if(str[indexOriginal] == ' ')
        {
            str[indexNew--] = '0';
            str[indexNew--] = '2';
            str[indexNew--] = '%';
        }
        else
        {
            str[indexNew--] = str[indexOriginal];
        }
        indexOriginal--;
    }
}

int main()
{
    char str[MAX] = " str str sss ";
    //char str[MAX] = " ";
    //char str[MAX] = "";
    replaceBlanks(MAX, str);

    cout << str;

    return 0;
}
