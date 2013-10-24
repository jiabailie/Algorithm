/* 
 * Largest Independent Set 
 * References : mp.weixin.qq.com/mp/appmsg/show?__biz=MjM5ODIzNDQ3Mw==&amp;appmsgid=10000312&amp;itemidx=1&amp;sign=0e53a19fb344fb7e09292a2e40e3ffab
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define DEBUG
#undef  DEBUG

using namespace std;

template<typename T>
inline T imax(T a, T b) { return a > b ? a : b; }

struct treeNode
{
        int data;
        treeNode* left;
        treeNode* right;
        int c[2];
        treeNode() : data(0), left(0), right(0) { c[0] = c[1] = 0; }
};

inline void createBinaryTree(treeNode*& root)
{
        int v = 0;
        cin >> v;
        if(v > -1)
        {
                root = new treeNode;
                root->data = v;
                createBinaryTree(root->left);
                createBinaryTree(root->right);
                if(!root->left && !root->right) { root->c[1] = 1; }
        }        
}

inline void destroyBinaryTree(treeNode*& root)
{
        if(!root) { return; }

        destroyBinaryTree(root->left);
        destroyBinaryTree(root->right);

        delete root;
}

inline void postOrderTraverseBinaryTree(treeNode*& root)
{
        if(!root) { cout << "The root is null." << endl; return; }

        treeNode* pre = 0;
        treeNode* top = 0;
        stack<treeNode*> istack;
        istack.push(root);

        while(!istack.empty())
        {
                top = istack.top();
                if((!top->left && !top->right) || (top->right && pre == top->right) || (top->left && !top->right && pre == top->left))
                {
#ifdef DEBUG
                        cout << top->data << " ";
#endif
                        istack.pop();
                        pre = top;
                        top->c[0] = (top->left ? imax(top->left->c[0], top->left->c[1]) : 0) + (top->right ? imax(top->right->c[0], top->right->c[1]) : 0);
                        top->c[1] = (top->left ? top->left->c[0] : 0) + (top->right ? top->right->c[0] : 0) + 1;
                        continue;
                }
                if(top->right) { istack.push(top->right); }
                if(top->left) { istack.push(top->left); }
        }
}

inline void displayBinaryTreeByLevel(const treeNode* root)
{
        if(!root) { cout << "The root is null." << endl; return; }

        int size = 0, i = 0;
        treeNode* front = 0;
        queue<treeNode*> iqueue;
        iqueue.push(const_cast<treeNode*>(root));

        while(!iqueue.empty())
        {
                size = iqueue.size();
                for(i = 0; i < size; i++)
                {
                        front = iqueue.front();
                        cout << front->data << " ";
                        
                        iqueue.pop();
                        if(front->left) { iqueue.push(front->left); }
                        if(front->right) { iqueue.push(front->right); }
                }
                cout << endl;
        }
}

int main()
{
        treeNode* root = 0;

        createBinaryTree(root);

        displayBinaryTreeByLevel(root);

#ifdef DEBUG
        cout << "Test post order traverse binary tree." << endl;
#endif
        postOrderTraverseBinaryTree(root);

        cout << endl << imax(root->c[0], root->c[1]) << endl;

        destroyBinaryTree(root);

        return 0;
}
