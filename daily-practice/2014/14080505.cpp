/**
 * Here is a binary tree, a path of a binary tree is defined as a order from the root to certain leaf, and there are no duplicate nodes in the path.
 * And there is a number, printing out all paths whose elements can composed the number.
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
typedef char dataType;
const int maxN = 10000;
struct BinaryTreeNode
{
	dataType m_cValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};
bool sumArray[maxN];
bool JudgePathSumSatisfied(int sum, const vector<int> &vecPath)
{
	if(sum >= maxN)
	{
		throw std::exception("Invalid input.");
	}
	int i = 0, j = 0;
	memset(sumArray, 0, sizeof(sumArray));
	sumArray[0] = true;

	for(i = 0; i < vecPath.size(); ++i)
	{
		for(j = maxN - 1; j >= 0; --j)
		{
			if(sumArray[j])
			{
				sumArray[j + vecPath[i]] = true;
			}
		}
	}

	return sumArray[sum];
}
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
	int iRootPos = 0;
	for(iRootPos = inStartPos; iRootPos <= inEndPos && inOrder[iRootPos] != preOrder[prePos]; ++iRootPos);
	if(iRootPos > inEndPos)
	{
		throw std::exception("Invalid input.");
	}
	if(inStartPos < iRootPos)
	{
		prePos += 1;
		pNewNode->m_pLeft = ReBuildBinaryTree(prePos, inStartPos, iRootPos - 1, preOrder, inOrder);
	}
	if(iRootPos < inEndPos)
	{
		prePos += 1;
		pNewNode->m_pRight = ReBuildBinaryTree(prePos, iRootPos + 1, inEndPos, preOrder, inOrder);
	}
	return pNewNode;
}
void PreOrderTraverseBinaryTree(BinaryTreeNode *root)
{
	if(!root) { return; }
	BinaryTreeNode *top = 0;
	stack<BinaryTreeNode*> istack;
	istack.push(root);
	while(!istack.empty())
	{
		top = istack.top();
		istack.pop();
		cout << top->m_cValue << " ";
		if(top->m_pRight)
		{
			istack.push(top->m_pRight);
		}
		if(top->m_pLeft)
		{
			istack.push(top->m_pLeft);
		}
		if(!top->m_pLeft && !top->m_pRight)
		{
			int way = 0;
		}
	}
	cout << endl;
}
void FindSatisfiedPath(int sum, vector<int> &vecPath, BinaryTreeNode *root)
{
	if(!root) { return; }
	vecPath.push_back(int(root->m_cValue - '0'));
	if(!root->m_pLeft && !root->m_pRight)
	{
		if(JudgePathSumSatisfied(sum, vecPath))
		{
			for(vector<int>::iterator it = vecPath.begin(); it != vecPath.end(); ++it)
			{
				cout << (*it) << " ";
			}
			cout << endl;
		}
	}
	if(root->m_pLeft)
	{
		FindSatisfiedPath(sum, vecPath, root->m_pLeft);
	}
	if(root->m_pRight)
	{
		FindSatisfiedPath(sum, vecPath, root->m_pRight);
	}
	vecPath.pop_back();
}
void DestroyBinaryTree(BinaryTreeNode **root)
{
	if(!root || !(*root)) { return; }
	if((*root)->m_pLeft)
	{
		DestroyBinaryTree(&((*root)->m_pLeft));
	}
	if((*root)->m_pRight)
	{
		DestroyBinaryTree(&((*root)->m_pRight));
	}
	delete (*root);
	*root = 0;
}
int main()
{
	int prePos = 0;
	int sum = 10;
	vector<int> vecPath;

	char *preOrder = "12485367";
	char *inOrder = "84251637";

	BinaryTreeNode *treeRoot = ReBuildBinaryTree(prePos, 0, strlen(inOrder) - 1, preOrder, inOrder);

	PreOrderTraverseBinaryTree(treeRoot);

	FindSatisfiedPath(sum, vecPath, treeRoot);

	DestroyBinaryTree(&treeRoot);

	return 0;
}