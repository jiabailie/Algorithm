#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <stack>
#include <vld.h>
#include "BinaryTree.h"

using namespace std;

void PrintingZigZagLevelOrder(TreeNode *p_Root)
{
	int curr = 0;
	int next = 1;
	TreeNode *p_Top = 0;
	stack<TreeNode*> istack[2];

	istack[curr].push(p_Root);
	while(!istack[curr].empty() || !istack[next].empty())
	{
		while(!istack[curr].empty())
		{
			p_Top = istack[curr].top();
			istack[curr].pop();

			if(!p_Top)
			{
				continue;
			}
			cout << p_Top->i_val << " ";
			// if curr = 0, push left node to stack at first
			if(curr == 0)
			{
				istack[next].push(p_Top->p_left);
				istack[next].push(p_Top->p_right);
			}
			else
			{
				istack[next].push(p_Top->p_right);
				istack[next].push(p_Top->p_left);
			}
		}
		curr = (curr + 1) % 2;
		next = (next + 1) % 2;
	}
	cout << endl;
}

int main()
{
	BinaryTreeMethod btObj;
	TreeNode *p_Root = btObj.DeserializeTree();

	PrintingZigZagLevelOrder(p_Root);

	btObj.DestroyTree(&p_Root);

	return 0;
}