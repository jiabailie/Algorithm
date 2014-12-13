#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <vld.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *BuildTree(int pos, int len, int *val)
{
	if(!val || pos < 0 || pos >= len)
	{
		return 0;
	}
	if(val[pos] == -1)
	{
		return 0;
	}
	TreeNode *newNode = new TreeNode(val[pos]);
	if(2 * pos + 1 < len)
	{
		newNode->left = BuildTree(2 * pos + 1, len, val);
	}
	if(2 * pos + 2 < len)
	{
		newNode->right = BuildTree(2 * pos + 2, len, val);
	}
	return newNode;
}

void DestroyTree(TreeNode **root)
{
	if(!root || !(*root))
	{
		return;
	}
	if((*root)->left)
	{
		DestroyTree(&((*root)->left));
	}
	if((*root)->right)
	{
		DestroyTree(&((*root)->right));
	}
	delete (*root);
	*root = 0;
}

void PreOrderTraverse(TreeNode *root)
{
	if(!root) { return; }
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
class Solution {
public:
	vector<vector<int> > reverseVector(vector<vector<int> > &vecObj)
	{
		vector<vector<int> > reverseRes;
		for(vector<vector<int> >::reverse_iterator it = vecObj.rbegin(); it != vecObj.rend(); ++it)
		{
			reverseRes.push_back(vector<int>(it->begin(), it->end()));
		}
		return reverseRes;
	}
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > ret;
		if(!root)
		{
			return ret;
		}
		int i = 0, j = 0;
		TreeNode *top = 0;
		queue<TreeNode*> level[2];
		level[i].push(root);
		while(!level[i].empty())
		{
			j = (i + 1) % 2;
			vector<int> curLevel;
			while(!level[i].empty())
			{
				top = level[i].front();
				level[i].pop();
				curLevel.push_back(top->val);
				if(top->left)
				{
					level[j].push(top->left);
				}
				if(top->right)
				{
					level[j].push(top->right);
				}
			}
			ret.push_back(curLevel);
			i = j;
		}
		return reverseVector(ret);
    }
};

int main()
{
	int val[] = {3, 9, 20, -1, -1, 15, 7};
	int len = sizeof(val) / sizeof(int);

	TreeNode *root = BuildTree(0, len, val);
	PreOrderTraverse(root);

	Solution sol;
	vector<vector<int> > ret = sol.levelOrderBottom(root);

	DestroyTree(&root);
	return 0;
}
