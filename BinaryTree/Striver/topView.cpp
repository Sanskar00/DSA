#include <iostream>
#include "btFunctions.h"
#include "BinaryTreeNode.h"
#include <queue>
#include <map>
#include <iterator>

vector<int> topView(BinaryTreeNode<int> *root)
{
    map<int, BinaryTreeNode<int> *> m;
    queue<pair<int, BinaryTreeNode<int> *>> q;
    pair<int,BinaryTreeNode<int> *> p;
    vector <int> res;
    p.first = 0;
    p.second = root;
    q.push(p);
    while (q.size() != 0)
    {
        BinaryTreeNode<int> *front = q.front().second;
        int frontIndex=q.front().first;
        q.pop();
        
        if(m.find(frontIndex)==m.end()){
            m[frontIndex]=front;
        }

        if(front->left){
            pair<int,BinaryTreeNode<int> *> ptemp;
            ptemp.first=frontIndex-1;
            ptemp.second=front->left;
            q.push(ptemp);
        }
        if(front->right){
            pair<int,BinaryTreeNode<int> *> ptemp;
            ptemp.first=frontIndex+1;
            ptemp.second=front->right;
            q.push(ptemp);
        }
    }

    map<int, BinaryTreeNode<int> *>::iterator itr;
    for(itr=m.begin();itr!=m.end();++itr){
        res.push_back(itr->second->data);
    }

    return res;

    
}

// 1 2 3 -1 -1 5 6 7 8 -1 -1 -1 -1 -1 -1
// 20 8 22 5 3 -1 25 -1 -1 10 14 -1 -1 -1 -1 -1 -1 
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    vector<int> vec=topView(root);
    cout<<"Bottom view of binary tree"<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
}
