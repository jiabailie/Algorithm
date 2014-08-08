/**
 * A binary tree, if the difference of its left sub-tree's height and right sub-tree's height is no more than 1,
 * this kind of binary tree is call balance binary tree.
 * Write program to judge whether the given binary tree is balance binary tree.
 */
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef char dataType;
struct BinaryTreeNode
{
	dataType m_cValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};
BinaryTreeNode *ReBuildBinaryTreeNode(int &prePos, int inStartPos, int inEndPos, const char *preOrder, const char *inOrder)
{
	if(!(preOrder && inOrder && prePos >= 0 && prePos < strlen(preOrder) && inStartPos >= 0 && inStartPos <= inEndPos && inEndPos < strlen(inOrder)))
	{
		return 0;
	}
	BinaryTreeNode *pNewNode = new BinaryTreeNode();
	pNewNode->m_cValue = preOrder[prePos];
	pNewNode->m_pLeft = 0;
	pNewNode->m_pRight = 0;
	if(inStartPos == inEndPos)
	{
		if(preOrder[prePos] != inOrder[inStartPos])
		{
			throw std::exception("Invalid input.");
		}
		return pNewNode;
	}
	int rootPos = 0;
	for(rootPos = inStartPos; rootPos <= inEndPos && inOrder[rootPos] != preOrder[prePos]; ++rootPos);
	if(rootPos > inEndPos)
	{
		throw std::exception("Invalid input.");
	}
	if(inStartPos < rootPos)
	{
		prePos += 1;
		pNewNode->m_pLeft = ReBuildBinaryTreeNode(prePos, inStartPos, rootPos - 1, preOrder, inOrder);
	}
	if(rootPos < inEndPos)
	{
		prePos += 1;
		pNewNode->m_pRight = ReBuildBinaryTreeNode(prePos, rootPos + 1, inEndPos, preOrder, inOrder);
	}
	return pNewNode;
}
int GetTreeHeight(BinaryTreeNode *pTreeRoot)
{
	if(!pTreeRoot) { return 0; }
	int leftHeight = GetTreeHeight(pTreeRoot->m_pLeft);
	int rightHeight = GetTreeHeight(pTreeRoot->m_pRight);
	return 1 + std::max(leftHeight, rightHeight);
}
bool IsBalanceTree(int &height, BinaryTreeNode *pTreeRoot)
{
	if(!pTreeRoot)
	{
		height = 0;
		return true;
	}
	int leftHeight = 0;
	int rightHeight = 0;
	if(IsBalanceTree(leftHeight, pTreeRoot->m_pLeft) && IsBalanceTree(rightHeight, pTreeRoot->m_pRight))
	{
		height = std::max(leftHeight, rightHeight) + 1;
		if(leftHeight - rightHeight <= 1 && leftHeight - rightHeight >= -1)
		{			
			return true;
		}
	}
	return false;
}
void DestroyBinaryTree(BinaryTreeNode **pTreeRoot)
{
	if(!pTreeRoot || !(*pTreeRoot))
	{
		return;
	}
	if((*pTreeRoot)->m_pLeft)
	{
		DestroyBinaryTree(&((*pTreeRoot)->m_pLeft));
	}
	if((*pTreeRoot)->m_pRight)
	{
		DestroyBinaryTree(&((*pTreeRoot)->m_pRight));
	}
	delete (*pTreeRoot);
	*pTreeRoot = 0;
}
int main()
{
	int prePos = 0;

	char *preOrder = "654";
	char *inOrder = "456";

	BinaryTreeNode *pRoot = ReBuildBinaryTreeNode(prePos, 0, strlen(inOrder) - 1, preOrder, inOrder);

	cout << GetTreeHeight(pRoot) << endl;

	cout << endl;

	int height = 0;
	bool isBalance = IsBalanceTree(height, pRoot);
	cout << (isBalance ? "Balance" : "Not balance") << endl;
	cout << height << endl;

	DestroyBinaryTree(&pRoot);

	return 0;
}