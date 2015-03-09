#include <queue>
#include <vld.h>
#include "BinaryTree.h"

using namespace std;

int GetMaxHeight(TreeNode *p_Root)
{
	if(!p_Root)
	{
		return 0;
	}
	return 1 + std::max(GetMaxHeight(p_Root->p_left), GetMaxHeight(p_Root->p_right));
}

void PrintLevel(TreeNode *p_Root, int i_Level)
{
	if(!p_Root) { return; }
	if(i_Level == 1)
	{
		cout << p_Root->i_val << " ";
		return;
	}
	PrintLevel(p_Root->p_left, i_Level - 1);
	PrintLevel(p_Root->p_right, i_Level - 1);
}

void PrintLevelOrder1(TreeNode *p_Root)
{
	if(!p_Root)
	{
		return;
	}
	int curr = 0;
	int next = 1;
	TreeNode *p_Top = 0;
	queue<TreeNode*> iqueue[2];
	iqueue[curr].push(p_Root);

	while(!iqueue[curr].empty() || !iqueue[next].empty())
	{
		while(!iqueue[curr].empty())
		{
			p_Top = iqueue[curr].front();
			iqueue[curr].pop();

			if(!p_Top) { continue; }

			cout << p_Top->i_val << " ";
			iqueue[next].push(p_Top->p_left);
			iqueue[next].push(p_Top->p_right);
		}
		cout << endl;
		curr = (curr + 1) % 2;
		next = (next + 1) % 2;
	}
}

void PrintLevelOrder2(TreeNode *p_Root)
{
	int i_Height = GetMaxHeight(p_Root);
	for(int i_Level = 1; i_Level <= i_Height; ++i_Level)
	{
		PrintLevel(p_Root, i_Level);
		cout << endl;
	}
}

int main()
{
	BinaryTreeMethod btObj;

	TreeNode *p_Root = btObj.DeserializeTree();

	PrintLevelOrder1(p_Root);

	PrintLevelOrder2(p_Root);

	btObj.DestroyTree(&p_Root);

	return 0;
}