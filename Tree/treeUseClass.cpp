#include <iostream>
#include "treeNodeClass.h"
#include <queue>

using namespace std;

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter no. of children of" << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->chilren.push_back(child);
    }

    return root;
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter num of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->chilren.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

void printTreeLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << "Your tree look like this" << endl;
    queue<TreeNode<int> *> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        TreeNode<int> *frontnode = pendingnodes.front();
        cout << frontnode->data << " : ";
        for (int i = 0; i < frontnode->chilren.size(); i++)
        {
            cout << frontnode->chilren[i]->data << ", ";
        }
        cout << endl;

        pendingnodes.pop();
        for (int i = 0; i < frontnode->chilren.size(); i++)
        {
            pendingnodes.push(frontnode->chilren[i]);
        }
    }
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    for (int i = 0; i < root->chilren.size(); i++)
    {
        cout << root->chilren[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->chilren.size(); i++)
    {
        printTree(root->chilren[i]);
    }
}

int countTreeNOde(TreeNode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->chilren.size(); i++)
    {
        ans += countTreeNOde(root->chilren[i]);
    }
    return ans;
}

int heightOfTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int maxheight = 0;
    int height = 1;
    for (int i = 0; i < root->chilren.size(); i++)
    {
        cout << "maxheight " << maxheight << " height " << height << " i " << i << " root->chilren[i] " << root->chilren[i]->data << endl;
        height = heightOfTree(root->chilren[i]);
        maxheight = max(maxheight, height);
    }

    return maxheight + 1;
}

void printLevelk(TreeNode<int> *root, int k)
{
    for (int i = 0; i < root->chilren.size(); i++)
    {
        if (k == 0)
        {
            cout << root->chilren[i]->data << ", ";
        }
        printLevelk(root->chilren[i], --k);
    }
}
void printleafnode(TreeNode<int> *root)
{
    if (root->chilren.size() == 0)
    {
        cout << root->data << " , ";
        return;
    }

    for (int i = 0; i < root->chilren.size(); i++)
    {
        printleafnode(root->chilren[i]);
    }
}

void preorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " "
         << " ";
    for (int i = 0; i < root->chilren.size(); i++)
    {
        preorder(root->chilren[i]);
    }
}

void postorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < root->chilren.size(); i++)
    {
        postorder(root->chilren[i]);
    }

    cout << root->data << " ";
}

void deletetree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root->chilren.size(); i++)
    {
        deletetree(root->chilren[i]);
    }

    delete root;
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 1 9 0
int main()
{
    // TreeNode <int> *root=new TreeNode<int>(1);
    // TreeNode <int> * node1=new TreeNode<int>(2);
    // TreeNode<int> * node2=new TreeNode<int>(3);

    // root->chilren.push_back(node1);
    // root->chilren.push_back(node2);

    // TreeNode <int> * root=takeInput();

    TreeNode<int> *root = takeInputLevelWise();
    // printTreeLevelWise(root);
    // preorder(root);
    // postorder(root);
    // deletetree(root);
    delete root;
    printTreeLevelWise(root);
    // printleafnode(root);
    // int k;
    // cout<<"k level "<<endl;
    // cin>>k;
    // cout<<"Node at level "+k<<endl;
    // printLevelk(root,k);
    // cout<<countTreeNOde(root)<<endl;
    // cout<<heightOfTree(root)<<endl;
}