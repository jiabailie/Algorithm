/**
 * Given a binary tree, and two nodes of it, find the Lowest Common Ancestor(LCA).
 */
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
struct BinaryTreeNode
{
	char m_cValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};
BinaryTreeNode *ReBuildBinaryTree(int &prePos, int inStartPos, int inEndPos, const char *preOrder, const char *inOrder)
{
	if(!(preOrder && inOrder && strlen(preOrder) == strlen(inOrder) && prePos >= 0 && prePos < strlen(preOrder) && inStartPos >= 0 && inStartPos <= inEndPos && inEndPos < strlen(inOrder)))
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
	int inRootPos = 0;
	for(inRootPos = inStartPos; inRootPos <= inEndPos && inOrder[inRootPos] != preOrder[prePos]; ++inRootPos);
	if(inRootPos > inEndPos)
	{
		throw std::exception("Invalid input.");
	}
	if(inStartPos < inRootPos)
	{
		prePos += 1;
		pNewNode->m_pLeft = ReBuildBinaryTree(prePos, inStartPos, inRootPos - 1, preOrder, inOrder);
	}
	if(inRootPos < inEndPos)
	{
		prePos += 1;
		pNewNode->m_pRight = ReBuildBinaryTree(prePos, inRootPos + 1, inEndPos, preOrder, inOrder);
	}
	return pNewNode;
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
BinaryTreeNode *LCA_BinarySearchTree(char nodeValue1, char nodeValue2, BinaryTreeNode *pTreeRoot)
{
	if(!pTreeRoot)
	{
		return 0;
	}
	if(nodeValue1 > nodeValue2)
	{
		std::swap(nodeValue1, nodeValue2);
	}
	BinaryTreeNode *pTop = 0;
	stack<BinaryTreeNode*> istack;
	istack.push(pTreeRoot);
	while(!istack.empty())
	{
		pTop = istack.top();
		if(nodeValue1 <= pTop->m_cValue && pTop->m_cValue <= nodeValue2)
		{
			return pTop;
		}
		istack.pop();
		if(pTop->m_pRight && pTop->m_cValue <= nodeValue1)
		{
			istack.push(pTop->m_pRight);
		}
		if(pTop->m_pLeft && pTop->m_cValue >= nodeValue2)
		{
			istack.push(pTop->m_pLeft);
		}
	}
	return 0;
}
int main()
{
	int prePos = 0;

	char *preOrder = "6435879";
	char *inOrder = "3456789";

	BinaryTreeNode *pTreeRoot = ReBuildBinaryTree(prePos, 0, strlen(preOrder) - 1, preOrder, inOrder);

	BinaryTreeNode *LCA = LCA_BinarySearchTree('5', '3', pTreeRoot);

	DestroyBinaryTree(&pTreeRoot);

	return 0;
}