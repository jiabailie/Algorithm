#include <queue>
#include <climits>
#include <vld.h>
#include "BinaryTree.h"

using namespace std;

/********Solution1 O(n)*********/
// Judge if current node is between the min and max,
// according to BST's attribute, we can know min and max.
bool isBSTHelper(TreeNode *p_Root, int i_Low, int i_High)
{
	if(!p_Root)
	{
		return true;
	}
	if(i_Low < p_Root->i_val && p_Root->i_val < i_High)
	{
		return isBSTHelper(p_Root->p_left, i_Low, p_Root->i_val) &&
			   isBSTHelper(p_Root->p_right, p_Root->i_val, i_High);
	}
	return false;
}
bool isBST(TreeNode *p_Root)
{
	return isBSTHelper(p_Root, INT_MIN, INT_MAX);
}
/********Solution2 O(n)*********/
// Using In-Order traverse.
bool isBSTInOrder(TreeNode *p_Root, int &i_Pre)
{
	if(!p_Root)
	{
		return true;
	}
	if(isBSTInOrder(p_Root->p_left, i_Pre))
	{
		if(p_Root->i_val > i_Pre)
		{
			i_Pre = p_Root->i_val;
			return isBSTInOrder(p_Root->p_right, i_Pre);
		}
		return false;
	}
	return false;
}

int main()
{
	BinaryTreeMethod btObj;

	TreeNode *p_Root = btObj.DeserializeTree();

	cout << "Solution 1 :" << (isBST(p_Root) ? "Yes" : "No") << endl;

	int i_Pre = INT_MIN;
	cout << "Solution 2 :" << (isBSTInOrder(p_Root, i_Pre) ? "Yes" : "No") << endl;

	btObj.DestroyTree(&p_Root);

	return 0;
}