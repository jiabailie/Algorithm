#include "LinkList.h"

LinkNode* LinkListMethod::CreateLinkList(int cur, std::vector<int> &vec_SerialLinkList)
{
	if(cur < 0 || cur >= int(vec_SerialLinkList.size()))
	{
		return 0;
	}
	LinkNode *p_Node = new LinkNode(vec_SerialLinkList[cur]);
	p_Node->p_next = CreateLinkList(cur + 1, vec_SerialLinkList);
	return p_Node;
}

void LinkListMethod::DisplayLinkList(LinkNode *p_Head)
{
	while(p_Head)
	{
		std::cout << p_Head->i_val << " ";
		p_Head = p_Head->p_next;
	}
	std::cout << std::endl;
}

void LinkListMethod::DestroyLinkList(LinkNode **p_Head)
{
	if(!p_Head || !(*p_Head))
	{
		return;
	}
	DestroyLinkList(&((*p_Head)->p_next));
	delete *p_Head;
	p_Head = 0;
}