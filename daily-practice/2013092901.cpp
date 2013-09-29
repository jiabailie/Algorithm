/* There is a Linklist {L1, L2, L3, ..., L(n - 2), L(n - 1), Ln}, reorder the Linklist into the form of 
 * {L1, Ln, L2, L(n -2), L3, L(n - 3), ... }
 */
#include <cstdio>
#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next;
};

void createLinkList(Node*& head)
{
	int v = 1;
	head = new Node;
	head->value = v;
	head->next = 0;

	Node* pre = head;
	Node* cur = 0;

	while(v > 0)
	{
		cin >> v;
		if(v > 0)
		{
			cur = new Node;
			cur->value = v;
			cur->next = 0;
			pre->next = cur;
			pre = cur;
		}
	}
}

void reorderLinkList(Node*& head)
{
	if(!head)
	{
		cout << "The linklist is null." << endl;
		return;
	}

	if(!head->next || !head->next->next) // Len == 1 || Len == 2
	{
		return;
	}

	Node* phead = head;
	Node* phead_next = head->next;
	Node* ptail_pre = head->next;
	Node* ptail = ptail_pre->next;

	while(ptail->next)
	{
		ptail_pre = ptail_pre->next;
		ptail = ptail->next;
	}

	while(true)
	{
		phead->next = ptail;
		ptail->next = phead_next;
		ptail_pre->next = 0;

		if(phead_next->next == ptail_pre)
		{
			break;
		}

		phead = phead_next;
		if(!phead || !phead->next)
		{
			break;
		}

		phead_next = phead->next;
		ptail_pre = phead_next;
		ptail = ptail_pre->next;
		while(ptail->next)
		{
			ptail_pre = ptail_pre->next;
			ptail = ptail->next;
		}
	}
}

void displayLinkList(Node* head)
{
	Node* cur = head;
	while(cur)
	{
		cout << cur->value << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main()
{
	Node* head = 0;

	createLinkList(head);

	displayLinkList(head);

	reorderLinkList(head);

	displayLinkList(head);

	return 0;
}
