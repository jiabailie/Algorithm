#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <vld.h>

using namespace std;

struct TreeNode
{
	int i_val;
	TreeNode *p_left;
	TreeNode *p_right;
	TreeNode() : i_val(0), p_left(0), p_right(0) {}
	TreeNode(int val) : i_val(val), p_left(0), p_right(0) {}
	TreeNode(const TreeNode &treeNode) : i_val(treeNode.i_val), p_left(treeNode.p_left), p_right(treeNode.p_right) {}
	TreeNode &operator=(const TreeNode &treeNode)
	{
		if(this != &treeNode)
		{
			this->i_val = treeNode.i_val;
			this->p_left = treeNode.p_left;
			this->p_right = treeNode.p_right;
		}
		return *this;
	}
};

// whether the next char is splitting token
inline bool isToken(char c, string &token)
{
	for(string::iterator it = token.begin(); it != token.end(); ++it)
	{
		if(c == (*it))
		{
			return true;
		}
	}
	return false;
}

// whether the next word is number or not
inline bool isNumber(string &str)
{
	if(str.size() == 0)
	{
		return false;
	}
	for(int i = 0; i < str.size(); ++i)
	{
		if(str[i] < '0' || str[i] > '9')
		{
			return false;
		}
	}
	return true;
}

// transfer a string to integer
int str2int(string &str)
{
	int ret = 0;
	for(int i = 0; i < str.size(); ++i)
	{
		ret = ret * 10 + (str[i] - '0');
	}
	return ret;
}

// read text from file
// here, the text in file is
// 30 10 50 # # # 20 45 # # 35 # #
vector<string> readFile(ifstream &in, string &token)
{
	if(!in.is_open())
	{
		cout << "Error during opening the file." << endl;
		exit(1);
	}
	char c;
	string word;
	vector<string> vec_Str;
	while(in.get(c))
	{
		if(!isToken(c, token))
		{
			word.push_back(c);
			continue;
		}

		if(word.length() > 0)
		{
			vec_Str.push_back(string(word.begin(), word.end()));
			word.clear();
		}
	}
	if(word.length() > 0)
	{
		vec_Str.push_back(string(word.begin(), word.end()));
	}

	return vec_Str;
}

// Deserialize the binary tree
TreeNode *DeserializeTree(int &cur, vector<string> &vec_SerialTree)
{
	if(cur < 0 || cur >= vec_SerialTree.size() || vec_SerialTree.size() == 0 || !isNumber(vec_SerialTree[cur]))
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
void SerializeTree(TreeNode *p_Root, ostream &out)
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

int main()
{
	string token(" ");
	ifstream in("D:/Lab/clab/file/1.txt");
	ofstream out("D:/Lab/clab/file/2.txt");

	vector<string> vec_SerialTree = readFile(in, token);

	int cur = 0;
	TreeNode *p_Root = DeserializeTree(cur, vec_SerialTree);

	if(out)
	{
		SerializeTree(p_Root, out);
	}

	DestroyTree(&p_Root);

	return 0;
}