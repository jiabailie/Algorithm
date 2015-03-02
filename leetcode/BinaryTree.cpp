#include "common.h"
#include "BinaryTree.h"

// Deserialize the binary tree
TreeNode* BinaryTreeMethod::DeserializeTree()
{
	std::string token(" ");

	std::ifstream in(str_InFilePath);

	std::vector<std::string> vec_SerialTree = readFile(in, token);

	int cur = 0;
	return DeserializeTree(cur, vec_SerialTree);
}
TreeNode* BinaryTreeMethod::DeserializeTree(int &cur, std::vector<std::string> &vec_SerialTree)
{
	if(cur < 0 || cur >= int(vec_SerialTree.size()) || vec_SerialTree.size() == 0 || !isNumber(vec_SerialTree[cur]))
	{
		return 0;
	}
	TreeNode *p_Node = new TreeNode(str2int(vec_SerialTree[cur]));
	cur = cur + 1;
	p_Node->p_left = DeserializeTree(cur, vec_SerialTree);
	cur = cur + 1;
	p_Node->p_right = DeserializeTree(cur, vec_SerialTree);

	return p_Node;
}

// Serialize the binary tree
void BinaryTreeMethod::SerializeTree(TreeNode *p_Root)
{
	std::ofstream out(str_OutFilePath);

	SerializeTree(p_Root, out);
}
void BinaryTreeMethod::SerializeTree(TreeNode *p_Root, std::ostream &out)
{
	if(!p_Root)
	{
		out << "# ";
	}
	else
	{
		out << p_Root->i_val << " ";
		SerializeTree(p_Root->p_left, out);
		SerializeTree(p_Root->p_right, out);
	}
}

// Release the resources
void BinaryTreeMethod::DestroyTree(TreeNode **p_Root)
{
	if(!p_Root || !(*p_Root))
	{
		return;
	}
	DestroyTree(&((*p_Root)->p_left));
	DestroyTree(&((*p_Root)->p_right));
	delete *p_Root;
	p_Root = 0;
}