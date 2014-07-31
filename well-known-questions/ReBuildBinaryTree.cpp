#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

typedef char dataType;

struct binaryTreeNode
{
	dataType m_cValue;
	binaryTreeNode *m_pLeft;
	binaryTreeNode *m_pRight;
};

binaryTreeNode *buildBinaryTree()
{
	binaryTreeNode *pBtreeNode = 0;
	dataType cValue;

	cin >> cValue;

	if(cValue == '#') { return 0; }

	pBtreeNode = new binaryTreeNode();

	pBtreeNode->m_cValue = cValue;
	pBtreeNode->m_pLeft = buildBinaryTree();
	pBtreeNode->m_pRight = buildBinaryTree();

	return pBtreeNode;
}

void destroyBinaryTree(binaryTreeNode **root)
{
	if(!(*root)) { return; }
	if((*root)->m_pLeft)
	{
		destroyBinaryTree(&((*root)->m_pLeft));
	}
	if((*root)->m_pRight)
	{
		destroyBinaryTree(&((*root)->m_pRight));
	}
	delete *root;
	*root = 0;
}

void preOrderTraverse(binaryTreeNode *root)
{
	if(!root) { return; }
	
	binaryTreeNode *pTop = 0;
	stack<binaryTreeNode*> istack;
	istack.push(root);

	while(!istack.empty())
	{
		pTop = istack.top();
		istack.pop();

		cout << pTop->m_cValue << " ";
		if(pTop->m_pRight)
		{
			istack.push(pTop->m_pRight);
		}
		if(pTop->m_pLeft)
		{
			istack.push(pTop->m_pLeft);
		}
	}
	cout << endl;
}

void inOrderTraverse(binaryTreeNode *root)
{
	if(!root) { return; }

	binaryTreeNode *pTop = 0;
	stack<binaryTreeNode*> istack;
	for(pTop = root; pTop; pTop = pTop->m_pLeft)
	{
		istack.push(pTop);
	}
	while(!istack.empty())
	{
		pTop = istack.top();
		istack.pop();

		cout << pTop->m_cValue << " ";
		if(pTop->m_pRight)
		{
			for(pTop = pTop->m_pRight; pTop; pTop = pTop->m_pLeft)
			{
				istack.push(pTop);
			}
		}
	}
	cout << endl;
}

void posOrderTraverse(binaryTreeNode *root)
{
	if(!root) { return; }

	binaryTreeNode *pTop = 0;
	binaryTreeNode *pPre = 0;
	stack<binaryTreeNode*> istack;
	istack.push(root);
	while(!istack.empty())
	{
		pTop = istack.top();
		if((!pTop->m_pLeft && !pTop->m_pRight) || (pTop->m_pRight && pPre == pTop->m_pRight) || (pTop->m_pLeft && !pTop->m_pRight && pPre == pTop->m_pLeft))
		{
			cout << pTop->m_cValue << " ";
			pPre = pTop;
			istack.pop();
			continue;
		}
		if(pTop->m_pRight)
		{
			istack.push(pTop->m_pRight);
		}
		if(pTop->m_pLeft)
		{
			istack.push(pTop->m_pLeft);
		}
	}
	cout << endl;
}

binaryTreeNode *ReBuildBinaryTree(int &prePos, int inStartPos, int inEndPos, const char *preOrder, const char *inOrder)
{
	int orderLen = strlen(preOrder);
	if(orderLen == 0 || !(prePos >= 0 && prePos < orderLen && inStartPos >= 0 && inStartPos <= inEndPos && inEndPos < orderLen) || strlen(preOrder) != strlen(inOrder))
	{
		return 0;
	}

	binaryTreeNode *pNewNode = new binaryTreeNode();
	pNewNode->m_cValue = preOrder[prePos];
	pNewNode->m_pLChild = 0;
	pNewNode->m_pRChild = 0;

	if(inStartPos == inEndPos)
	{
		if(preOrder[prePos] != inOrder[inStartPos])
		{
			delete pNewNode;
			throw std::exception("Invalid input.");
		}
		return pNewNode;
	}

	int inPos = 0;
	for(inPos = inStartPos; inPos <= inEndPos && inOrder[inPos] != preOrder[prePos]; ++inPos);
	if(inPos > inEndPos)
	{
		delete pNewNode;
		throw std::exception("Invalid input.");
	}
	
	if(inPos != inStartPos)
	{
		prePos += 1;
		pNewNode->m_pLChild = ReBuildBinaryTree(prePos, inStartPos, inPos - 1, preOrder, inOrder);
	}
	if(inPos != inEndPos)
	{
		prePos += 1;
		pNewNode->m_pRChild = ReBuildBinaryTree(prePos, inPos + 1, inEndPos, preOrder, inOrder);
	}

	return pNewNode;
}

int main()
{
	int prePos = 0;
	int inStartPos = 0;
	int inEndPos = 3;

	char *preOrder = "1234";
	char *inOrder = "1234";

	binaryTreeNode *root = 0;

	root = reBuildBinaryTree(prePos, inStartPos, inEndPos, preOrder, inOrder);

	preOrderTraverse(root);

	inOrderTraverse(root);

	posOrderTraverse(root);

	destroyBinaryTree(&root);

	return 0;
}