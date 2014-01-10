#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct tnode
{
	int parent;
	int left;
	int right;
	tnode(int _parent, int _left, int _right) : parent(_parent), left(_left), right(_right)	{}
};

void left_rotate(int& root, int& node, vector<tnode>& tree)
{
	int nright = tree[node].right;
	int left = -1;
	if(nright != -1)
	{
		left = tree[nright].left;
	}

	if(node == root)
	{
		root = tree[node].right;
	}
	
	if(nright != -1)
	{
		tree[nright].left = node;
	}
	if(node != -1)
	{
		tree[node].parent = nright;
		tree[node].right = left;
	}
	if(left != -1)
	{
		tree[left].parent = node;
	}
}

void right_rotate(int& root, int& node, vector<tnode>& tree)
{
	int nleft = tree[node].left;
	int right = -1;

	if(nleft != -1)
	{
		right = tree[nleft].right;
	}

	if(node == root)
	{
		root = nleft;
	}

	if(nleft != -1)
	{
		tree[nleft].right = node;
	}
	if(node != -1)
	{
		tree[node].parent = nleft;
		tree[node].left = right;
	}
	if(right != -1)
	{
		tree[right].parent = node;
	}
}

void inorder(int root, vector<tnode>& tree)
{
	stack<int> istack;
	int top = root;

	while(top != -1)
	{
		istack.push(top);
		top = tree[top].left;
	}

	while(!istack.empty())
	{
		int top = istack.top();
		istack.pop();
		printf("%d\n", top);
		top = tree[top].right;
		while(top != -1)
		{
			istack.push(top);
			top = tree[top].left;
		}
	}
}

int main()
{
	int i = 0, j = 0;
	int k = 0, q = 0, root = 0;
	int c = 0, l = 0, r = 0;
	int m = 0, cur = 0, oper = 0;	

	scanf("%d", &k);

	for(i = 0; i < k; i++)
	{
		vector<tnode> tree(15, tnode(-1, -1, -1));

		scanf("%d", &q);
		for(j = 0; j < q; j++)
		{
			scanf("%d %d %d", &c, &l, &r);
			tree[c].left = l;
			tree[c].right = r;
			if(l != -1)	tree[l].parent = c;
			if(r != -1) tree[r].parent = c;
		}
		for(j = 0; j < q; j++)
		{
			if(tree[j].parent == -1)
			{
				root = j;
				break;
			}
		}
		scanf("%d", &m);
		for(j = 0; j < m; j++)
		{
			scanf("%d %d", &cur, &oper);
			if(oper == 0)
			{
				left_rotate(root, cur, tree);
			}
			else
			{
				right_rotate(root, cur, tree);
			}
		}
		inorder(root, tree);
	}
	return 0;
}
