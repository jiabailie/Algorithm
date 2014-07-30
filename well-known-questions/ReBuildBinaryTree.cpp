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

binaryTreeNode *reBuildBinaryTree(int &prePos, int inStartPos, int inEndPos, const char *preOrder, const char *inOrder)
{
	if(strlen(preOrder) == 0 || strlen(inOrder) == 0 || strlen(preOrder) != strlen(inOrder))
	{
		return 0;
	}

	binaryTreeNode *rootNode = new binaryTreeNode();
	rootNode->m_cValue = preOrder[prePos];
	rootNode->m_pLeft = 0;
	rootNode->m_pRight = 0;

	if(inStartPos == inEndPos) { return rootNode; }

	int i = 0;
	for(i = inStartPos; i <= inEndPos && inOrder[i] != preOrder[prePos]; ++i);
	if(i != inStartPos)
	{
		prePos += 1;
		rootNode->m_pLeft = reBuildBinaryTree(prePos, inStartPos, i - 1, preOrder, inOrder);
	}
	if(i != inEndPos)
	{
		prePos += 1;
		rootNode->m_pRight = reBuildBinaryTree(prePos, i + 1, inEndPos, preOrder, inOrder);
	}

	return rootNode;
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