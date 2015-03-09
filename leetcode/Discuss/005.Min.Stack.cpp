#include <cstdio>
#include <iostream>
#include <stack>
#include <exception>
using namespace std;

class MinStack {
private:
	stack<int> rawStack;
	stack<int> minStack;
public:
	MinStack()
	{
		while(!rawStack.empty())
		{
			rawStack.pop();
		}
		while(!minStack.empty())
		{
			minStack.pop();
		}
	}
	~MinStack()
	{

	}
    void push(int x) {
		rawStack.push(x);
		if(minStack.empty())
		{
			minStack.push(x);
			return;
		}
		int currMin = minStack.top();
		if(currMin > x)
		{
			currMin = x;
		}
		minStack.push(currMin);
    }

    void pop() {
        if(rawStack.empty())
		{
			throw std::runtime_error("The stack is empty.");
		}
		rawStack.pop();
		minStack.pop();
    }

    int top() {
        if(rawStack.empty())
		{
			throw std::runtime_error("The stack is empty.");
		}
		return rawStack.top();
    }

    int getMin() {
        if(minStack.empty())
		{
			throw std::runtime_error("The stack is empty.");
		}
		return minStack.top();
    }
};

int main()
{
	return 0;
}