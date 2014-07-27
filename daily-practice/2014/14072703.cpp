#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

typedef char datatype;

struct BinaryTreeNode
{
public:
	datatype data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

/* Building the binary tree in pre-order */
BinaryTreeNode *buildBinaryTree()
{
	char nodeV;
	cin >> nodeV;
	if(nodeV == '#')
	{
		return 0;
	}
	BinaryTreeNode *btnode = new BinaryTreeNode();
	btnode->data = nodeV;
	btnode->left = buildBinaryTree();
	btnode->right = buildBinaryTree();
	return btnode;
}

/* Destroy the binary tree */
void removeBTree(BinaryTreeNode *root)
{
	if(!root) { return; }
	removeBTree(root->left);
	removeBTree(root->right);
	if(!root->left && !root->right)
	{
		delete root;
		root = 0;
	}
}

void preOrderTraverseBTree(BinaryTreeNode *root)
{
	if(!root) { return; }

	BinaryTreeNode *top = 0;

	stack<BinaryTreeNode*> istack;
	istack.push(root);

	while(!istack.empty())
	{
		top = istack.top();
		istack.pop();
		cout << top->data << " ";
		if(top->right)
		{
			istack.push(top->right);
		}
		if(top->left)
		{
			istack.push(top->left);
		}
	}

	cout << endl << endl;
}

void inOrderTraverseBTree(BinaryTreeNode *root)
{
	if(!root) { return; }

	BinaryTreeNode *top = 0;

	stack<BinaryTreeNode*> istack;
	
	for(top = root; top; top = top->left)
	{
		istack.push(top);
	}
	while(!istack.empty())
	{
		top = istack.top();
		istack.pop();
		cout << top->data << " ";
		if(!top->right) { continue; }
		for(top = top->right; top; top = top->left)
		{
			istack.push(top);
		}
	}
	cout << endl << endl;
}

void posOrderTraverseBTree(BinaryTreeNode *root)
{
	if(!root) { return; }
	
	BinaryTreeNode *top = 0;
	BinaryTreeNode *pre = 0;

	stack<BinaryTreeNode*> istack;

	istack.push(root);

	while(!istack.empty())
	{
		top = istack.top();
		if((!top->left && !top->right) || (top->right && pre == top->right) || (top->left && !top->right && pre == top->left))
		{
			pre = top;
			istack.pop();
			cout << top->data << " ";
			continue;
		}
		if(top->right && pre != top->right)
		{
			istack.push(top->right);
		}
		if(top->left && pre != top->left)
		{
			istack.push(top->left);
		}
	}
	cout << endl << endl;
}

/* Get the height of the binary tree */
int getBinaryTreeHeight(BinaryTreeNode *root)
{
	if(!root) { return 0; }
	if(!root->left && !root->right) { return 1; }

	return 1 + std::max(getBinaryTreeHeight(root->left), getBinaryTreeHeight(root->right));
}

/* Swap the binary tree's two branches */
void swapBinaryTreeBranch(BinaryTreeNode *root)
{
	if(!root) { return; }
	
	BinaryTreeNode *tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	swapBinaryTreeBranch(root->left);
	swapBinaryTreeBranch(root->right);
}

int main()
{
	// abdf##g##e##c##
	BinaryTreeNode *root = buildBinaryTree();

	swapBinaryTreeBranch(root);

	cout << "Pre-order traverse:" << endl;
	preOrderTraverseBTree(root);

	cout << "In-order traverse:" << endl;
	inOrderTraverseBTree(root);

	cout << "Pos-order traverse:" << endl;
	posOrderTraverseBTree(root);

	int treeHeight = getBinaryTreeHeight(root);
	cout << "The binary tree's height is " << treeHeight << endl;

	removeBTree(root);
	return 0;
}