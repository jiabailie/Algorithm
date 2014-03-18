#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define DEBUG

using namespace std;

struct TreeNode
{
    int level;
    int value;
    vector<TreeNode*> offsprings;

    TreeNode() : level(0), value(0)
    {}

    TreeNode(const TreeNode &_treeNode) : 
        level(_treeNode.level), 
        value(_treeNode.value), 
        offsprings(vector<TreeNode*>(_treeNode.offsprings.begin(), _treeNode.offsprings.end()))
    {}

    TreeNode(int _level, int _value, vector<TreeNode*> _offsprings = vector<TreeNode*>()) :
        level(_level),
        value(_value),
        offsprings(_offsprings.begin(), _offsprings.end())
    {}

    ~TreeNode()
    {
        if(offsprings.size() > 0)
        {
            for(vector<TreeNode*>::iterator it = offsprings.begin(); it != offsprings.end(); ++it)
            {
                delete (*it);
                *it = 0;
            }
        }
    }

    TreeNode& operator=(const TreeNode &_treeNode)
    {
        if(this == &_treeNode)
        {
            return *this;
        }

        level = _treeNode.level;
        value = _treeNode.value;
        offsprings = vector<TreeNode*>(_treeNode.offsprings.begin(), _treeNode.offsprings.end());

        return *this;
    }

    void push_back(TreeNode *_treeNode)
    {
        if(this == _treeNode)
        {
            return;
        }

        for(vector<TreeNode*>::iterator it = offsprings.begin(); it != offsprings.end(); ++it)
        {
            if(*it == _treeNode)
            {
                return;
            }
        }
        offsprings.push_back(_treeNode);
    }

    void pop_back()
    {
        if(offsprings.size() > 0)
        {
            offsprings.pop_back();
        }
    }

    bool empty()
    {
        return offsprings.empty();
    }

    size_t size()
    {
        return offsprings.size();
    }
};

class TreeOperations
{
private:
    TreeNode *root;

    map<int, TreeNode*> v2n;

public:
    void CreateTree(vector<pair<int, int> >&);

    void GenerateTreeLevelValues();

    void VisitTreeByLevel();
};

/**
 * Create a new tree using a string.
 * default root and (parent, child) pairs.
 * root's value is 0.
 */
void TreeOperations::CreateTree(vector<pair<int, int> > &relations)
{
    root = new TreeNode(0, 0);

    v2n[0] = root;

    for(vector<pair<int, int> >::iterator it = relations.begin(); it != relations.end(); ++it)
    {
        if(it->first != 0)
        {
            v2n[it->first] = new TreeNode(0, it->first);
        }

        v2n[it->second] = new TreeNode(0, it->second);
    }

    for(vector<pair<int, int> >::iterator it = relations.begin(); it != relations.end(); ++it)
    {
        v2n[it->first]->offsprings.push_back(v2n[it->second]);
    }
}

/**
 * Generate tree level values.
 */
void TreeOperations::GenerateTreeLevelValues()
{
    queue<TreeNode*> iqueue;
    TreeNode* tmp = 0;

    iqueue.push(root);

    while(!iqueue.empty())
    {
        tmp = iqueue.front();

        iqueue.pop();

        for(vector<TreeNode*>::iterator it = tmp->offsprings.begin(); it != tmp->offsprings.end(); ++it)
        {
            (*it)->level = tmp->level + 1;
            iqueue.push(*it);
        }
    }
}

/**
 * Visit tree by its level.
 */
void TreeOperations::VisitTreeByLevel()
{
    map<int, vector<int> > treeLevel;
    queue<TreeNode*> iqueue;
    TreeNode* tmp = 0;

    iqueue.push(root);

    while(!iqueue.empty())
    {
        tmp = iqueue.front();
        treeLevel[tmp->level].push_back(tmp->value);

        iqueue.pop();

        for(vector<TreeNode*>::iterator it = tmp->offsprings.begin(); it != tmp->offsprings.end(); ++it)
        {
            iqueue.push(*it);
        }
    }

    for(map<int, vector<int> >::iterator it = treeLevel.begin(); it != treeLevel.end(); ++it)
    {
        cout << "Level " << it->first << ": ";
        for(vector<int>::iterator iit = it->second.begin(); iit != it->second.end(); ++iit)
        {
            cout << (*iit) << " ";
        }
        cout << endl;
    }
}

int main()
{
    TreeOperations to;

#ifdef    DEBUG
    vector<pair<int, int> > relations;

    relations.push_back(pair<int, int>(0, 1));
    relations.push_back(pair<int, int>(0, 2));
    relations.push_back(pair<int, int>(0, 3));
    relations.push_back(pair<int, int>(1, 4));
    relations.push_back(pair<int, int>(1, 5));
    relations.push_back(pair<int, int>(5, 8));
    relations.push_back(pair<int, int>(3, 6));
    relations.push_back(pair<int, int>(3, 7));
#endif

    to.CreateTree(relations);

    to.GenerateTreeLevelValues();

    to.VisitTreeByLevel();

    return 0;
}