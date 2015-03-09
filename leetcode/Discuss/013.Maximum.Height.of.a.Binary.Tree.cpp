#include <cstdio>
#include <iostream>
#include <vld.h>
#include <stack>
#include <set>

using namespace std;

struct TreeNode
{
	char val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(char c) : val(c) {}
};

TreeNode *BuildTree(int cur, char *data)
{
	if(!data || strlen(data) == 0 || cur < 0 || cur >= strlen(data) || data[cur] == '#')
	{
		return 0;
	}
	TreeNode *newNode = new TreeNode(data[cur]);
	newNode->left = BuildTree(2 * cur + 1, data);
	newNode->right = BuildTree(2 * cur + 2, data);

	return newNode;
}

void PreOrderTraverse(TreeNode *root)
{
	if(!root)
	{
		return;
	}
	TreeNode *top = 0;
	stack<TreeNode*> istack;
	istack.push(root);
	while(!istack.empty())
	{
		top = istack.top();
		istack.pop();
		cout << top->val << " ";
		if(top->right)
		{
			istack.push(top->right);
		}
		if(top->left)
		{
			istack.push(top->left);
		}
	}
	cout << endl;
}

void InOrderTraverse(TreeNode *root)
{
	if(!root)
	{
		return;
	}
	TreeNode *top = root;
	stack<TreeNode*> istack;
	while(top)
	{
		istack.push(top);
		top = top->left;
	}
	while(!istack.empty())
	{
		top = istack.top();
		istack.pop();
		cout << top->val << " ";
		if(top->right)
		{
			top = top->right;
			while(top)
			{
				istack.push(top);
				top = top->left;
			}
		}
	}
	cout << endl;
}

void PosOrderTraverse(TreeNode *root)
{
	if(!root)
	{
		return;
	}
	TreeNode *top = 0;
	TreeNode *pre = 0;
	stack<TreeNode*> istack;
	istack.push(root);
	while(!istack.empty())
	{
		top = istack.top();
		if((!top->left && !top->right) || (top->right && pre == top->right) || (top->left && !top->right && pre == top->left))
		{
			cout << top->val << " ";
			pre = top;
			istack.pop();
		}
		else
		{
			if(top->left && !top->right && pre != top->left)
			{
				istack.push(top->left);
			}
			else if(!top->left && top->right && pre != top->right)
			{
				istack.push(top->right);
			}
			else if(top->left && top->right && pre != top->left && pre != top->right)
			{
				istack.push(top->right);
				istack.push(top->left);
			}
		}
	}
	cout << endl;
}

int GetTreeMaxHeight(TreeNode *root)
{
	if(!root)
	{
		return 0;
	}
	return std::max(GetTreeMaxHeight(root->left), GetTreeMaxHeight(root->right)) + 1;
}

int GetTreeMaxHeightIterative(TreeNode *root)
{
	if(!root)
	{
		return 0;
	}
	int treeHeight = 0;
	TreeNode *top = root;
	set<char> visited;
	stack<TreeNode*> istack;
	istack.push(root);
	while(!istack.empty())
	{
		treeHeight = std::max(treeHeight, int(istack.size()));
		top = istack.top();
		visited.insert(top->val);
		if((!top->left && !top->right) || 
		   (top->left && !top->right && visited.find(top->left->val) != visited.end()) ||
		   (top->right && visited.find(top->right->val) != visited.end()))
		{
			istack.pop();
		}
		else if(top->left && visited.find(top->left->val) == visited.end())
		{
			istack.push(top->left);
		}
		else if(top->right && visited.find(top->right->val) == visited.end())
		{
			istack.push(top->right);
		}
	}
	return treeHeight;
}

void DestroyTree(TreeNode **root)
{
	if(!root || !(*root))
	{
		return;
	}
	DestroyTree(&((*root)->left));
	DestroyTree(&((*root)->right));
	delete (*root);
	*root = 0;
}

int main()
{
	char *data = "abcdefg##i#####";

	TreeNode *root = BuildTree(0, data);

	cout << "Pre Order Traverse:";
	PreOrderTraverse(root);

	cout << "In Order Traverse:";
	InOrderTraverse(root);

	cout << "Pos Order Traverse:";
	PosOrderTraverse(root);

	cout << "Tree Height is(recursive): " << GetTreeMaxHeight(root) << endl;

	cout << "Tree Height is(non-recursive): " << GetTreeMaxHeightIterative(root) << endl;

	DestroyTree(&root);

	return 0;
}