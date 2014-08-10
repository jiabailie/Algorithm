/**
 * To a general binary tree, and its two nodes, find the Lowest Common Ancestor(LCA).
 * Test case : 
 * (1) nodeValue1 == nodeValue2
 * (2) nodeValue1 != nodeValue2 and they are belong to different sub-trees.
 * (3) nodeValue1 != nodeValue2 and they are belong to the same sub-tree.
 * (4) nodeValue1 or nodeValue2 is not in the binary tree.
 */
#include <cstdio>
#include <iostream>
using namespace std;
struct BinaryTreeNode
{
	char m_cValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};
BinaryTreeNode *ReBuildBinaryTree(int &prePos, int inStartPos, int inEndPos, const char *preOrder, const char *inOrder)
{
	if(!(preOrder && 
		 inOrder && 
		 strlen(preOrder) == strlen(inOrder) && 
		 prePos >= 0 && 
		 prePos < strlen(preOrder) && 
		 inStartPos >= 0 && 
		 inStartPos <= inEndPos && 
		 inEndPos < strlen(inOrder)))
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
int LCA_GeneralBinaryTree(char nodeValue1, char nodeValue2, BinaryTreeNode *pTreeRoot, BinaryTreeNode **pLCANode)
{
	if(!pTreeRoot) { return 0; }
	if(nodeValue1 == nodeValue2 && nodeValue1 == pTreeRoot->m_cValue)
	{
		*pLCANode = pTreeRoot;
		return 2;
	}
	int iLeft = LCA_GeneralBinaryTree(nodeValue1, nodeValue2, pTreeRoot->m_pLeft, pLCANode);
	int iRight = LCA_GeneralBinaryTree(nodeValue1, nodeValue2, pTreeRoot->m_pRight, pLCANode);
	if(pTreeRoot->m_cValue == nodeValue1 || pTreeRoot->m_cValue == nodeValue2)
	{
		if(iLeft == 1 || iRight == 1)
		{
			*pLCANode = pTreeRoot;
			return 2;
		}
		return 1;
	}
	if(iLeft == 2 || iRight == 2)
	{
		return 2;
	}
	if(iLeft + iRight == 2)
	{
		*pLCANode = pTreeRoot;
	}
	return iLeft + iRight;
}
int main()
{
	int prePos = 0;

	char *preOrder = "6435879";
	char *inOrder = "3456789";

	BinaryTreeNode *pTreeRoot = ReBuildBinaryTree(prePos, 0, strlen(preOrder) - 1, preOrder, inOrder);

	BinaryTreeNode *LCANode = 0; 
	int isFind = LCA_GeneralBinaryTree('2', '8', pTreeRoot, &LCANode);
	if(isFind == 2)
	{
		cout << LCANode->m_cValue << endl;
	}
	else
	{
		cout << "Can not find the LCA." << endl;
	}
	DestroyBinaryTree(&pTreeRoot);

	return 0;
}