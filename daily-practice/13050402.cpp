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

/* pre-order traverse binary tree */
void preOrder(Node root)
{
    if(!root) { return; }
    int top = -1;
    Node stack[MAX];
    Node tmp = 0;
    stack[++top] = root;
    while(top > -1)
    {
        tmp = stack[top--];
        cout << tmp->data << " ";
        if(tmp->right)
        {
            stack[++top] = tmp->right;
        }
        if(tmp->left)
        {
            stack[++top] = tmp->left;
        }
    }
}

/* in-order traverse binary tree */
void inOrder(Node root)
{
    if(!root) { return; }
    int top = -1;
    Node stack[MAX];
    Node tmp = root;
    while(tmp)
    {
        stack[++top] = tmp;
        tmp = tmp->left;
    }
    while(top > -1)
    {
        tmp = stack[top--];
        cout << tmp->data << " ";
        if(tmp->right)
        {
            tmp = tmp->right;
            while(tmp)
            {
                stack[++top] = tmp;
                tmp = tmp->left;
            }
        }
    }
}

/* post-order traverse binary tree */
void postOrder(Node root)
{
    if(!root) { return; }
    int top = -1;
    Node stack[MAX];
    Node pre = 0;
    Node tmp = 0;
    stack[++top] = root;
    while(top > -1)
    {
        tmp = stack[top];
        if(!tmp->left && !tmp->right)
        {
            pre = tmp;
            cout << tmp->data << " ";
            top--;
        }
        else if(tmp->left && !tmp->right)
        {
            if(pre == tmp->left)
            {
                pre = tmp;
                cout << tmp->data << " ";
                top--;
            }
            else if(pre != tmp->left)
            {
                stack[++top] = tmp->left;
            }
        }
        else if(!tmp->left && tmp->right)
        {
            if(pre == tmp->right)
            {
                pre = tmp;
                cout << tmp->data << " ";
                top--;
            }
            else if(pre != tmp->right)
            {
                stack[++top] = tmp->right;
            }
        }
        else if(tmp->left && tmp->right)
        {
            if(pre == tmp->left)
            {
                stack[++top] = tmp->right;
            }
            else if(pre == tmp->right)
            {
                pre = tmp;
                cout << tmp->data << " ";
                top--;
            }
            else if(pre != tmp->left && pre != tmp->right)
            {
                stack[++top] = tmp->left;
            }
        }
    }
}

int main()
{
    Node root;
    buildTree(root);
    postOrder(root);

    return 0;
}
