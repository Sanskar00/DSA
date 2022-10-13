#include <iostream>
#include "btFunctions.h"
#include "BinaryTreeNode.h"

void helperLowestCommonAncestor(BinaryTreeNode<int> * root,BinaryTreeNode <int> * temp,BinaryTreeNode<int> * ans,BinaryTreeNode<int>*p,BinaryTreeNode<int>*q){

    if(root==NULL){
        return;
    }
    if(root->left==p || root->right==q){
        temp=root;
    }

    if((temp->left==p && root->right==q) || ( root->left==p && temp->left==q) ){
        ans=temp;
    }

    helperLowestCommonAncestor(temp->left,temp,ans,p,q);
    helperLowestCommonAncestor(temp->right,temp,ans,p,q);

}

BinaryTreeNode<int> *lowestCommonAncestor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *p, BinaryTreeNode<int> *q)
{
    if(root==NULL){
        return root;
    }
    BinaryTreeNode <int> * temp=root;
    BinaryTreeNode <int> * ans=root;
    helperLowestCommonAncestor(root,temp,ans,p,q);

    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
}