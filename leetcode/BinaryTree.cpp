#include "BinaryTree.h"

// whether the next char is splitting token
inline bool isToken(char c, std::string &token)
{
	for(std::string::iterator it = token.begin(); it != token.end(); ++it)
	{
		if(c == (*it))
		{
			return true;
		}
	}
	return false;
}

// whether the next word is number or not
inline bool isNumber(std::string &str)
{
	if(str.size() == 0)
	{
		return false;
	}
	for(size_t i = 0; i < str.size(); ++i)
	{
		if(str[i] < '0' || str[i] > '9')
		{
			return false;
		}
	}
	return true;
}

// transfer a string to integer
int str2int(std::string &str)
{
	int ret = 0;
	for(size_t i = 0; i < str.size(); ++i)
	{
		ret = ret * 10 + (str[i] - '0');
	}
	return ret;
}

// read text from file
std::vector<std::string> readFile(std::ifstream &in, std::string &token)
{
	if(!in.is_open())
	{
		std::cout << "Error during opening the file." << std::endl;
		exit(1);
	}
	char c;
	std::string word;
	std::vector<std::string> vec_Str;
	while(in.get(c))
	{
		if(!isToken(c, token))
		{
			word.push_back(c);
			continue;
		}

		if(word.length() > 0)
		{
			vec_Str.push_back(std::string(word.begin(), word.end()));
			word.clear();
		}
	}
	if(word.length() > 0)
	{
		vec_Str.push_back(std::string(word.begin(), word.end()));
	}

	return vec_Str;
}

// Deserialize the binary tree
TreeNode *DeserializeTree()
{
	std::string token(" ");

	std::ifstream in(str_InFilePath);

	std::vector<std::string> vec_SerialTree = readFile(in, token);

	int cur = 0;
	return DeserializeTree(cur, vec_SerialTree);
}
TreeNode *DeserializeTree(int &cur, std::vector<std::string> &vec_SerialTree)
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
void SerializeTree(TreeNode *p_Root)
{
	std::ofstream out(str_OutFilePath);

	SerializeTree(p_Root, out);
}
void SerializeTree(TreeNode *p_Root, std::ostream &out)
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
void DestroyTree(TreeNode **p_Root)
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