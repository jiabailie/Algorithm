#include <cstdio>
#include <iostream>
#include <climits>

using namespace std;

struct Node
{
	int val;
	Node *left;
	Node *right;
	Node(char _val) : val(_val), left(0), right(0) {}
};

bool isBSTHelper(Node *p, int low, int high)
{
	if(!p) { return true; }
	if(low < p->val && p->val < high)
	{
		return isBSTHelper(p->left, low, p->val) &&
			   isBSTHelper(p->right, p->val, high);
	}

	return false;
}

bool isBST(Node *root)
{
	return isBSTHelper(root, INT_MIN, INT_MAX);
}