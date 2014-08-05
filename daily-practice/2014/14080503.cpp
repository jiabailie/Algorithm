/**
 * If there is a push stack order, and another pop stack order.
 * Judge whether the push stack order can lead to the pop stack order.
 * eg. Push order = { 1, 2, 3, 4, 5, 6, 7 };
 *     Pop order = {1, 2, 3, 4, 5, 6, 7 } is legal, and { 1, 4, 2, 3, 5, 6, 7 } is not legal.
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
bool judgeLegalStackPushPopOrder(const char *pushOrder, const char *popOrder)
{
	if(!pushOrder || !popOrder || strlen(pushOrder) != strlen(popOrder))
	{
		return false;
	}
	stack<char> istack;
	int orderLen = strlen(pushOrder);
	int pushIndex = 0, popIndex = 0;
	while(pushIndex < orderLen && popIndex != orderLen)
	{
		if(!istack.empty() && popIndex != orderLen && istack.top() == popOrder[popIndex])
		{
			istack.pop();
			popIndex += 1;
			continue;
		}
		while(pushIndex < orderLen && pushOrder[pushIndex] != popOrder[popIndex])
		{
			istack.push(pushOrder[pushIndex]);
			pushIndex += 1;
		}
		if(pushIndex == orderLen) { return false; }
		popIndex += 1;
		pushIndex += 1;
	}
	if(popIndex == orderLen)
	{
		return true;
	}
	return false;
}
int main()
{
	char *pushOrder = "1234567";
	char *popOrder = "1423567";
	bool legal = judgeLegalStackPushPopOrder(pushOrder, popOrder);
	cout << "Push order:" << pushOrder << endl;
	cout << "Pop order:" << popOrder << endl;
	cout << (legal ? "legal" : "illegal") << endl;
	return 0;
}