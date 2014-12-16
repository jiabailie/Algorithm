#include <cstdio>
#include <iostream>
#include <vld.h>

using namespace std;

struct Node
{
	char val;
	Node *next;
	Node(char val) : val(val), next(0) {}
};

Node* BuildLinkList(const char *vals)
{
	if(!vals || strlen(vals) == 0)
	{
		return 0;
	}
	Node *head = new Node(vals[0]);
	Node *curr = head;
	Node *next = 0;
	for(int i = 1; i < strlen(vals); ++i)
	{
		next = new Node(vals[i]);
		curr->next = next;
		curr = next;
	}
	return head;
}

void reverseIterative(Node **head)
{
	if(!head || !(*head)) { return; }
	Node *pre = 0;
	Node *cur = *head;
	Node *pos = 0;
	while(cur)
	{
		pos = cur->next;
		cur->next = pre;
		pre = cur;
		cur = pos;
	}
	*head = pre;
}

void reverseRecursive(Node **head)
{
	if(!head || !(*head)) { return; }
	Node *pos = (*head)->next;
	if(!pos) { return; }
	reverseRecursive(&pos);
	(*head)->next->next = *head;
	(*head)->next = 0;
	*head = pos;
}

void DisplayLinkList(Node *head)
{
	if(!head)
	{
		return;
	}
	for(Node *i = head; i; i = i->next)
	{
		cout << i->val << " ";
	}
	cout << endl;
}
void DestroyLinkList(Node **head)
{
	if(!head || !(*head))
	{
		return;
	}
	Node *pre = *head;
	Node *pos = *head;
	while(pos)
	{
		pre = pos;
		pos = pos->next;
		delete pre;
	}
	*head = 0;
}
int main()
{
	char song[] = "abcdefghijk";

	Node *head = BuildLinkList(song);

	DisplayLinkList(head);

	reverseIterative(&head);
	cout << "reverse iterative:" << endl;
	DisplayLinkList(head);

	reverseRecursive(&head);
	cout << "reverse recursive:" << endl;
	DisplayLinkList(head);

	DestroyLinkList(&head);

	return 0;
}