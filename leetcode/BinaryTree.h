#ifndef _BINARYHEAD_H
#define _BINARYHEAD_H

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <vld.h>

const std::string str_InFilePath = "D:/Lab/clab/file/1.txt";
const std::string str_OutFilePath = "D:/Lab/clab/file/1.txt";

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
inline bool isToken(char c, std::string &token);

// whether the next word is number or not
inline bool isNumber(std::string &str);

// transfer a string to integer
int str2int(std::string &str);

// read text from file
std::vector<std::string> readFile(std::ifstream &in, std::string &token);

// Deserialize the binary tree
TreeNode *DeserializeTree();
TreeNode *DeserializeTree(int &cur, std::vector<std::string> &vec_SerialTree);

// Serialize the binary tree
void SerializeTree(TreeNode *p_Root);
void SerializeTree(TreeNode *p_Root, std::ostream &out);

// Release the resources
void DestroyTree(TreeNode **p_Root);

#endif