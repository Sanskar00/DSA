#include <iostream>
#include "BinaryTreeNode.H"
#include "btFunctions.h"

BinaryTreeNode<int> * searchNode(BinaryTreeNode<int>* root,int x){
    if(root==NULL || root->data==x){
        return root;
    }

    if(root->data>x){
        searchNode(root->left,x);
    }else if(root->data<x){
        searchNode(root->right,x);
    }
}

bool ifNode(BinaryTreeNode<int> * root,int x){
    BinaryTreeNode<int> * node=searchNode(root,x);
    if(node==NULL){
        return false;
    }else{
        return true;
    }
}
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
int main(){
    BinaryTreeNode <int> * root=takeInputLevelWise();
    printTreeLevelWise(root);
    int x;
    cout<<"enter data to be found"<<endl;
    cin>>x;
    cout<<"Data to be found is ";
    cout<<ifNode(root,x)<<endl;
}