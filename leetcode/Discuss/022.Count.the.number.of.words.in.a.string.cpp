#include <stdio.h>

bool isalpha(char c)
{
	if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ',' || c == '.')
	{
		return true;
	}
	return false;
}

int countNumWords(const char *str)
{
	bool inWord = false;
	int wordCount = 0;
	while(*str)
	{
		if(!inWord && isalpha(*str))
		{
			inWord = true;
			wordCount += 1;
		}
		else if(inWord && *str == ' ')
		{
			inWord = false;
		}
		str += 1;
	}
	return wordCount;
}

int main()
{
	char *str = "Hello, my name is John.";

	printf("%d\n", countNumWords(str));

	return 0;
}