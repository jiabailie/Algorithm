#include <cstdio>
#include <iostream>

using namespace std;

struct Node
{
	Node *leftChild;
	Node *rightChild;
	Node *nextRight;
};

void connect1(Node* p)
{
	if(!p || !p->leftChild || !p->rightChild) { return; }
	Node *rightSibling = 0;
	Node *p1 = p;
	while(p1)
	{
		if(p1->nextRight)
		{
			rightSibling = p1->nextRight->leftChild;
		}
		else
		{
			rightSibling = 0;
		}
		p1->leftChild->nextRight = p1->rightChild;
		p1->rightChild->nextRight = rightSibling;
		p1 = p1->nextRight;
	}
	connect1(p->leftChild);
}

void connect2(Node *p)
{
	if(!p) { return; }
	if(p->leftChild)
	{
		p->leftChild->rightChild = p->rightChild;
	}
	if(p->rightChild)
	{
		p->rightChild->nextRight = p->nextRight ? p->nextRight->leftChild : 0;
	}
	connect2(p->leftChild);
	connect2(p->rightChild);
}

int main()
{
	return 0;
}