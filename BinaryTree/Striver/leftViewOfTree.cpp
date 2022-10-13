#include <iostream>
#include "btFunctions.h"
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

vector<int> getLeftView(BinaryTreeNode<int> *root)
{
    //    Write your code here
    queue<BinaryTreeNode<int> *> q;
    vector<int> res;
    q.push(root);
    q.push(NULL);
    res.push_back(root->data);
    while (q.size() != 0)
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (front)
        {
            cout << front->data << endl;
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        else
        {
            cout << "inside else" << endl;
            if (q.size() > 0)
            {
                res.push_back(q.front()->data);
                q.push(NULL);
            }
        }
    }
    return res;
}

// 1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    vector<int> res = getLeftView(root);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
}