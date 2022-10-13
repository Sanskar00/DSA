#include <iostream>
#include "btFunctions.h"
#include "BinaryTreeNode.h"
#include <stack>
using namespace std;

void zigZag(BinaryTreeNode<int> *root)
{
    stack<BinaryTreeNode<int> *> s1, s2;
    s1.push(root);
    while (s1.size() != 0 || s2.size() != 0)
    {
        if(s1.size()!=0){
            cout<<s1.top()->data<<" ";
            if(s1.size()==1){
                cout<<endl;
            }
            if(s1.top()->left){
                s2.push(s1.top()->left);
            }
            if(s1.top()->right){
                s2.push(s1.top()->right);
            }
            s1.pop();
        }else if(s2.size()!=0){
            cout<<s2.top()->data<<" ";
            if(s2.size()==1){
                cout<<endl;
            }
            if(s2.top()->right){
                s1.push(s2.top()->right);
            }
            if(s2.top()->left){
                s1.push(s2.top()->left);
            }
            s2.pop();
        }
 }
}
// 3 9 20 -1 -1 15 7 -1 -1 -1 -1

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    zigZag(root);
}