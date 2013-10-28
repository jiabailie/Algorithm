#include <cstdio>
#include <iostream>
#include "PriorityQueue.h"

class node
{
public:
	int key;
	int value;
	node(void) : key(0), value(0) {}
	node(const int _key, const int _value) { key = _key; value = _value; }
};

int main()
{
	int k = 0, i = 0;
	const int n = 10;
	PriorityQueue<node> pq;

	for(i = 0; i < n; i++)
	{
		k = rand() % 1000;
		Single<node>* single = new Single<node>(k, new node(k, k * 100));
		pq.push(single);
	}

	while(!pq.empty())
	{
		Single<node>* single = pq.pop();
		cout << single->key << " ";
	}
	cout << endl;
	return 0;
}
