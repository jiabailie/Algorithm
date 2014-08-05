/**
 * Design a stack, which has O(1) time complexity for push, pop, min operations.
 */
#include <cstdio>
#include <stack>
#include <iostream>
#include <cstring>
#include <vector>
#include "common.h"
using namespace std;
struct MinStack
{
private:
	stack<int> rawStack;
	stack<int> minStack;
public:
	MinStack();
	~MinStack();
	void push(int);
	void pop();
	int top();
	bool empty();
};

MinStack::MinStack()
{
	while(!this->minStack.empty())
	{
		this->minStack.pop();
	}
	while(!this->rawStack.empty())
	{
		this->rawStack.pop();
	}
}

MinStack::~MinStack() {}

void MinStack::push(int element)
{
	rawStack.push(element);
	if(minStack.empty())
	{		
		minStack.push(element);
		return;
	}
	int currMin = minStack.top();
	if(element < currMin)
	{
		currMin = element;
	}
	minStack.push(currMin);
}

void MinStack::pop()
{
	if(rawStack.empty())
	{
		throw std::exception("The stack is empty.");
	}
	minStack.pop();
	rawStack.pop();
}

int MinStack::top()
{
	if(rawStack.empty())
	{
		throw std::exception("The stack is empty.");
	}
	return minStack.top();
}

bool MinStack::empty()
{
	return rawStack.empty();
}

int main()
{
	vector<int> arrayObj;
	makeArray(arrayObj);
	displayArray(arrayObj);

	MinStack minStack;

	for(vector<int>::iterator it = arrayObj.begin(); it != arrayObj.end(); ++it)
	{
		minStack.push(*it);
	}

	while(!minStack.empty())
	{
		cout << minStack.top() << " ";
		minStack.pop();
	}
	cout << endl;

	return 0;
}