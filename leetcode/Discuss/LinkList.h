#ifndef _LINKLISTHEAE_H
#define _LINKLISTHEAE_H

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <vld.h>

const std::string str_InFilePath = "D:/Lab/clab/file/linklist.txt";

struct LinkNode
{
	int i_val;
	LinkNode *p_next;
	LinkNode() : i_val(0), p_next(0) {}
	LinkNode(int val) : i_val(val), p_next(0) {}
	LinkNode(const LinkNode &linkNode) : i_val(linkNode.i_val), p_next(linkNode.p_next) {}
	LinkNode &operator=(const LinkNode &linkNode)
	{
		if(this != &linkNode)
		{
			this->i_val = linkNode.i_val;
			this->p_next = linkNode.p_next;
		}
		return *this;
	}
};

class LinkListMethod
{
public:
	LinkNode *CreateLinkList(int cur, std::vector<int> &vec_SerialLinkList);

	void DisplayLinkList(LinkNode *p_Head);

	void DestroyLinkList(LinkNode **p_Head);
};
#endif