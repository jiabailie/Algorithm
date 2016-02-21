#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value) : value(value), left(NULL), right(NULL) {}
};

void InorderMorrisTraversal(TreeNode* root) {
	TreeNode* cur = root;
	TreeNode* prev = NULL;

	while (cur != NULL) {
		if (cur->left == NULL) {
			cout << cur->value << " ";
			cur = cur->right;
		}
		else {
			prev = cur->left;
			while (prev->right != NULL && prev->right != cur) {
				prev = prev->right;
			}

			if (prev->right == NULL) {
				prev->right = cur;
				cur = cur->left;
			}
			else {
				prev->right = NULL;
				cout << cur->value << " ";
				cur = cur->right;
			}
		}
	}
}

void PreorderMorrisTraversal(TreeNode* root) {
	TreeNode* cur = root;
	TreeNode* prev = NULL;

	while (cur != NULL) {
		if (cur->left == NULL) {
			cout << cur->value << " ";
			cur = cur->right;
		}
		else {
			prev = cur->left;
			while (prev->right != NULL && prev->right != cur) {
				prev = prev->right;
			}

			if (prev->right == NULL) {
				cout << cur->value << " ";
				prev->right = cur;
				cur = cur->left;
			}
			else {
				prev->right = NULL;
				cur = cur->right;
			}
		}
	}
}

TreeNode* CreateBinaryTree(int& preOrderIndex, int inStart, int inEnd, vector<int>& preOrder, vector<int>& inOrder) {
	if (preOrderIndex < 0 || preOrderIndex >= preOrder.size() || inStart > inEnd) {
		return NULL;
	}

	int inOrderIndex = -1;
	for (int i = inStart; i <= inEnd; ++i) {
		if (preOrder[preOrderIndex] == inOrder[i]) {
			inOrderIndex = i;
			break;
		}
	}
	if (inOrderIndex == -1) {
		return NULL;
	}

	TreeNode* root = new TreeNode(preOrder[preOrderIndex]);
	if (inStart < inEnd) {
		preOrderIndex += 1;
		root->left = CreateBinaryTree(preOrderIndex, inStart, inOrderIndex - 1, preOrder, inOrder);
		if (!root->left) {
			preOrderIndex -= 1;
		}

		preOrderIndex += 1;
		root->right = CreateBinaryTree(preOrderIndex, inOrderIndex + 1, inEnd, preOrder, inOrder);
		if (!root->right) {
			preOrderIndex -= 1;
		}
	}

	return root;
}

void DestroyBinaryTree(TreeNode*& root) {
	if (!root) {
		return;
	}

	DestroyBinaryTree(root->left);
	DestroyBinaryTree(root->right);

	delete root;
}

int main() {
	int preData[] = { 0, 1, 3, 4, 2, 5, 6 };
	int inData[] = { 3, 1, 4, 0, 5, 2, 6 };

	vector<int> preOrder(preData, preData + sizeof(preData) / sizeof(int));
	vector<int> inOrder(inData, inData + sizeof(inData) / sizeof(int));

	int preOrderIndex = 0;
	TreeNode* root = CreateBinaryTree(preOrderIndex, 0, inOrder.size() - 1, preOrder, inOrder);

	InorderMorrisTraversal(root);

	cout << endl;

	PreorderMorrisTraversal(root);

	DestroyBinaryTree(root);

	return 0;
}