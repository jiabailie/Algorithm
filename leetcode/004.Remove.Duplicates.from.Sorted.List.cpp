#include <cstdio>
#include <iostream>
#include <set>
#include <vld.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *BuildList(int cur, int len, int *val)
{
	if(!val || cur < 0 || cur >= len)
	{
		return 0;
	}
	ListNode *head = new ListNode(val[cur]);
	head->next = BuildList(cur + 1, len, val);
	return head;
}
void DisplayList(ListNode *head)
{
	if(!head)
	{
		return;
	}
	for(; head; head = head->next)
	{
		cout << head->val << " ";
	}
	cout << endl;
}
void DestroyList(ListNode ** list)
{
	if(!list || !(*list))
	{
		return;
	}
	if((*list)->next)
	{
		DestroyList(&((*list)->next));
	}
	delete (*list);
	*list = 0;
}
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)
		{
			return 0;
		}
		ListNode *res = head;
		ListNode *cur = head;
		ListNode *tmp = 0;
		set<int> inserted;
		inserted.insert(head->val);
		head = head->next;
		cur->next = 0;
		while(head)
		{
			tmp = head;
			head = head->next;
			if(inserted.find(tmp->val) == inserted.end())
			{
				cur->next = tmp;
				cur = cur->next;
				cur->next = 0;
				inserted.insert(tmp->val);
			}
			else
			{
				delete tmp;
				tmp = 0;
			}
		}
		return res;
    }
};
int main()
{
	int val[] = {1, 1, 2, 3, 3};
	int len = sizeof(val) / sizeof(int);

	ListNode *head = BuildList(0, len, val);

	DisplayList(head);

	Solution sol;

	ListNode *rem = sol.deleteDuplicates(head);

	DisplayList(rem);

	DestroyList(&head);

	return 0;
}