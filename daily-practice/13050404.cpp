/* Traverse binary tree */
#include <cstdio>
#include <iostream>
#include <cstdlib>
#define MAX 100

using namespace std;

typedef struct node
{
    node* left;
    node* right;
    int data;
} *Node;

/* create binary tree */
void buildTree(Node& root)
{
    int d = 0;
    cin >> d;
    if(d > 0)
    {
        root = new node;
        root->left = 0;
        root->right = 0;
        root->data = d;
        buildTree(root->left);
        buildTree(root->right);
    }
}

/* Traverse the binary tree by level */
void levelTree(Node root)
{
    if(!root) { return; }
    int head = 0, tail = 0;
    Node queue[MAX];
    Node tmp = 0;
    queue[tail++] = root;
    while(head != tail)
    {
        tmp = queue[head];
        head = (head + 1) % MAX;
        cout << tmp->data << " ";
        if(tmp->left)
        {
            queue[tail] = tmp->left;
            tail = (tail + 1) % MAX;
        }
        if(tmp->right)
        {
            queue[tail] = tmp->right;
            tail = (tail + 1) % MAX;
        }
    }
}

int main()
{
    Node root;

    buildTree(root);
    levelTree(root);

    return 0;
}
