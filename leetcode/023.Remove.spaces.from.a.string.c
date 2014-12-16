#include <stdio.h>
#include <vld.h>

void removeSpace(char *str)
{
	char *p = str;
	char *q = str;
	while(*p)
	{
		if(*p != ' ')
		{
			*q = *p;
			q += 1;
		}
		p += 1;
	}
	*q = 0;
}

int main()
{
	char str[100] = "abc de  fg hi jk lll mm n";

	removeSpace(str);

	printf("%s\n", str);

	return 0;
}