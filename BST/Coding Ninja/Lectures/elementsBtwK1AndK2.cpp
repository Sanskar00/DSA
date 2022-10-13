#include <iostream>
#include "BinaryTreeNode.H"
#include "btFunctions.h"

void printNodeInRange(BinaryTreeNode<int>* root,int k1,int k2){
    if(root==NULL){
        return ;
    }

    if(k1<=root->data && root->data<=k2){
        cout<<root->data<<" ";
    }

    if(k1<=root->data){
        printNodeInRange(root->left,k1,k2);
    }
    if(k2>=root->data){
        printNodeInRange(root->right,k1,k2);
    }

}

// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
int main(){
    BinaryTreeNode <int> * root=takeInputLevelWise();
    printTreeLevelWise(root);
    int k1;
    cout<<"Enter k1"<<endl;
    cin>>k1;
    int k2;
    cout<<"Enter k2"<<endl;
    cin>>k2;
    printNodeInRange(root,k1,k2);
}