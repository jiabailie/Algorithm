#include <cstdio>
#include <iostream>
#include <vector>
#include "LinkList.h"
#include <vld.h>

using namespace std;

void FrontBackSplit(LinkNode *p_head, LinkNode **p_front, LinkNode **p_back) 
{
	if(!p_head)
	{
		return;
	}
	LinkNode *p_front_last_node = 0;
	LinkNode *p_slow = p_head;
	LinkNode *p_fast = p_head;
	while(p_fast)
	{
		p_front_last_node = p_slow;
		p_slow = p_slow->p_next;
		p_fast = p_fast->p_next ? p_fast->p_next->p_next : 0;
	}
	p_front_last_node->p_next = 0;
	*p_front = p_head;
	*p_back = p_slow;
}

int main()
{
	LinkListMethod llMethod;

	int val[] = {2, 3, 5, 7, 11};
	vector<int> vec = vector<int>(val, val + sizeof(val) / sizeof(int));

	LinkNode *p_Head = llMethod.CreateLinkList(0, vec);

	llMethod.DisplayLinkList(p_Head);

	LinkNode *p_front = 0;
	LinkNode *p_back = 0;

	FrontBackSplit(p_Head, &p_front, &p_back);	

	llMethod.DisplayLinkList(p_front);

	llMethod.DisplayLinkList(p_back);

	llMethod.DestroyLinkList(&p_front);

	llMethod.DestroyLinkList(&p_back);

	return 0;
}