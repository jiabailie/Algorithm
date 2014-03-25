#include <cstdio>
#include <iostream>

using namespace std;

const int n = 70;
const int mod = 997;

struct node
{
	int val;
	node *next;
	node() : val(-1), next(0) {}
	node(int _val, node *_next) : val(_val), next(_next) {}
	node(const node& _node) : val(_node.val), next(_node.next) {}
	node& operator=(const node& _node)
	{
		if(this == &_node)
		{
			return *this;
		}
		this->val = _node.val;
		this->next = _node.next;
		return *this;
	}
};

void create(node *head, int n, int *arr)
{	
	node *p = head;
	node *t = 0;

	for(int i = 0; i < n; ++i)
	{
		t = new node(arr[i], 0);
		p->next = t;
		p = t;
	}
	p->next = 0;
}

void del(node *head)
{
	node *p = head;
	node *q = 0;
	while(p)
	{
		q = p->next;
		delete p;
		p = 0;
		
		if(q)
		{
			p = q;
		}
	}
}

void display(node *head)
{
	for(node *p = head->next; p; p = p->next)
	{
		cout << p->val << " ";
	}
	cout << endl;
}

// sort the list as non-descending order
void lsort(node *head)
{
	if(!head->next || !head->next->next)
	{
		return;
	}

	int t = 0;
	node *p = head->next;
	node *q = 0;
	node *m = 0;

	while(p)
	{
		q = p;
		m = p;
		for(; q; q = q->next)
		{
			if(m->val > q->val)
			{
				m = q;
			}
		}
		if(m != p)
		{
			t = m->val;
			m->val = p->val;
			p->val = t;
		}
		p = p->next;
	}
}

int main()
{
	int d[n];

	for(int i = 0; i < n; ++i)
	{
		d[i] = rand() % mod;
	}

	node *head = new node();

	create(head, n, d);

	cout << "Before the sort:" << endl;

	display(head);

	lsort(head);

	cout << "After the sort:" << endl;

	display(head);

	del(head);

	return 0;
}