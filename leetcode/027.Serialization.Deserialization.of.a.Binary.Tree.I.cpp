#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <vld.h>

using namespace std;

struct Node
{
	char val;
	Node *left;
	Node *right;
	Node(char _val) : val(_val), left(0), right(0) {}
};

Node *buildTree(int cur, const char *p)
{
	if(!p || cur >= strlen(p) || p[cur] == '#')
	{
		return 0;
	}
	Node *newNode = new Node(p[cur]);
	int left = cur * 2 + 1;
	int right = cur * 2 + 2;
	newNode->left = buildTree(left, p);
	newNode->right = buildTree(right, p);
	return newNode;
}

void displayTree(Node *root)
{
	if(!root) { return; }
	Node *top = root;
	stack<Node*> istack;
	istack.push(root);
	while(!istack.empty())
	{
		top = istack.top();
		istack.pop();
		if(!top)
		{
			cout << "#";
			continue;
		}
		cout << top->val;
		istack.push(top->right);
		istack.push(top->left);
	}
	cout << endl;
}

void dispalyTreeByLevel(Node *root)
{
	if(!root) { return; }
	Node *front = 0;
	queue<Node*> iqueue;
	iqueue.push(root);
	while(!iqueue.empty())
	{
		front = iqueue.front();
		iqueue.pop();
		if(!front)
		{
			cout << "#";
			continue;
		}
		cout << front->val;
		iqueue.push(front->left);
		iqueue.push(front->right);
	}
	cout << endl;
}

void destroyTree(Node **root)
{
	if(!root || !(*root))
	{
		return;
	}
	if((*root)->left)
	{
		destroyTree(&((*root)->left));
	}
	if((*root)->right)
	{
		destroyTree(&((*root)->right));
	}
	delete (*root);
	*root = 0;
}

int main()
{
	char *p = "abcde####f#";

	Node *root = buildTree(0, p);

	displayTree(root);

	dispalyTreeByLevel(root);

	destroyTree(&root);

	return 0;
}