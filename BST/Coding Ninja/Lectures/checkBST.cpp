#include <iostream>
#include "BinaryTreeNode.H"
#include "btFunctions.h"

bool checkBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    // return (root->left && root->right) &&
    //        root->left->data < root->data && root->data < root->right->data;
    if (root->left)
    {
        if (root->left->data > root->data)
        {
            cout << "inside root left" << endl;
            return false;
        }
    }

    if (root->right)
    {
        if (root->right->data < root->data)
        {
            cout << "inside root right" << endl;
            return false;
        }
    }

    bool left=checkBST(root->left);
    bool right=checkBST(root->right);

    return (left && right);

}

// 3 1 5 -1 2 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    bool check = checkBST(root);
    cout << check << endl;
}