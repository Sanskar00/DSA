#include <iostream>
#include "btFunctions.h"
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int> *removeLeafNode(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        root = NULL;
        return root;
    }

    root->left = removeLeafNode(root->left);
    root->right = removeLeafNode(root->right);
}

// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    cout << "after removing leaf node " << endl;
    removeLeafNode(root);
    printTreeLevelWise(root);
}