/**
 * In a binary tree, calculate the amount of nodes which only has one child.
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
BinaryTreeNode *ReBuildBinaryTreeNode(int &prePos, int inStartPos, int inEndPos, const char *preOrder, const char *inOrder)
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
		pNewNode->m_pLeft = ReBuildBinaryTreeNode(prePos, inStartPos, inRootPos - 1, preOrder, inOrder);
	}
	if(inRootPos < inEndPos)
	{
		prePos += 1;
		pNewNode->m_pRight = ReBuildBinaryTreeNode(prePos, inRootPos + 1, inEndPos, preOrder, inOrder);
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
void PostOrderTraverseBinaryTree(BinaryTreeNode *pTreeRoot)
{
	if(!pTreeRoot) { return; }
	stack<BinaryTreeNode*> istack;
	BinaryTreeNode *top = 0;
	BinaryTreeNode *pre = 0;
	istack.push(pTreeRoot);
	while(!istack.empty())
	{
		top = istack.top();
		if((!top->m_pLeft && !top->m_pRight) || (top->m_pRight && pre == top->m_pRight) || (top->m_pLeft && !top->m_pRight && pre == top->m_pLeft))
		{
			cout << top->m_cValue << " ";
			istack.pop();
			pre = top;
			continue;
		}
		if(top->m_pRight)
		{
			istack.push(top->m_pRight);
		}
		if(top->m_pLeft)
		{
			istack.push(top->m_pLeft);
		}
	}
	cout << endl;
}
int CalHasOneChildTreeNode(BinaryTreeNode *pTreeRoot)
{
	if(!pTreeRoot) { return 0; }
	int res = 0;
	stack<BinaryTreeNode*> istack;
	BinaryTreeNode *top = 0;
	BinaryTreeNode *pre = 0;
	istack.push(pTreeRoot);
	while(!istack.empty())
	{
		top = istack.top();
		if((!top->m_pLeft && !top->m_pRight) || (top->m_pRight && pre == top->m_pRight) || (top->m_pLeft && !top->m_pRight && pre == top->m_pLeft))
		{
			if((top->m_pLeft && !top->m_pRight) || (!top->m_pLeft && top->m_pRight)) { res += 1; }
			istack.pop();
			pre = top;
			continue;
		}
		if(top->m_pRight)
		{
			istack.push(top->m_pRight);
		}
		if(top->m_pLeft)
		{
			istack.push(top->m_pLeft);
		}
	}
	return res;
}
int main()
{
	int prePos = 0;

	char *preOrder = "abdecf";
	char *inOrder = "dbeafc";

	BinaryTreeNode *pTreeRoot = ReBuildBinaryTreeNode(prePos, 0, strlen(preOrder) - 1, preOrder, inOrder);

	PostOrderTraverseBinaryTree(pTreeRoot);

	int oneChildNodeAmount = CalHasOneChildTreeNode(pTreeRoot);

	cout << oneChildNodeAmount << endl;

	DestroyBinaryTree(&pTreeRoot);

	return 0;
}