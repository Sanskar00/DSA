#include <iostream>
#include <cstdlib>
#include "btFunctions.h"
#include "BinaryTreeNode.h"
using namespace std;

pair <int,int> helperBalanced(BinaryTreeNode<int> * root){
    if(root==NULL){
        pair <int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    // cout<<root->data<<endl;

    pair<int,int> leftNode=helperBalanced(root->left);
    pair<int,int> rightNode=helperBalanced(root->right);



    int df=abs(leftNode.second-rightNode.second);
    
    pair <int,int> p;

    p.first=df;
    p.second=1+max(leftNode.second,rightNode.second);

    // cout<<p.second<<endl;

    return p;


}

bool checkBalanced(BinaryTreeNode <int> * root ){
    pair <int,int> resPair=helperBalanced(root);
    if(resPair.first>1){
        return false;
    }else{
        return true;
    }
    
}

// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 1 2 3 -1 -1 -1 -1
int main(){
    BinaryTreeNode <int> * root =takeInputLevelWise();
    printTreeLevelWise(root);
    cout<<checkBalanced(root)<<endl;
}