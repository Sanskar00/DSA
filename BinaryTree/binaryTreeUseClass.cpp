#include <iostream>
#include <queue>
#include "BinaryTreeNodeClass.h"
using namespace std;

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    if (root->left)
    {
        cout << "L" << root->left->data << " ";
    }
    if (root->right)
    {
        cout << "R" << root->right->data << " ";
    }

    cout << endl;

    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

void printTreeLevelWise(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        cout << front->data << ":";
        pendingNodes.pop();

        if (front->left)
        {
            BinaryTreeNode<int> *leftChild = front->left;
            cout << "L" << leftChild->data << " ";
            pendingNodes.push(leftChild);
        }

        if (front->right)
        {
            BinaryTreeNode<int> *rightChild = front->right;
            cout << "R" << rightChild->data;
            pendingNodes.push(rightChild);
        }

        cout << endl;
    }
}

int countNodes(BinaryTreeNode<int> *root)
{
    int count = 0;
    int leftCount = 0;
    int rightCount = 0;
    if (root == NULL)
    {
        return count;
    }

    leftCount = leftCount + countNodes(root->left);
    rightCount = rightCount + countNodes(root->right);

    count = leftCount + rightCount;

    return count + 1;
}

void helperNodePresent(BinaryTreeNode<int> *root, int x, bool &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == x)
    {
        ans = true;
    }
    if (root->left)
    {
        helperNodePresent(root->left, x, ans);
    }

    if (root->right)
    {
        helperNodePresent(root->right, x, ans);
    }
}

bool nodePresent(BinaryTreeNode<int> *root, int x)
{
    bool ans = false;
    helperNodePresent(root, x, ans);
    return ans;
}

int heightOfTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftheight = heightOfTree(root->left);
    int rightheight = heightOfTree(root->right);

    return max(leftheight, rightheight) + 1;
}

void mirrorTree(BinaryTreeNode<int> *root)
{
    cout<<"Your mirrored tree"<<endl;
    queue<BinaryTreeNode<int> *> pendingQueue;
    pendingQueue.push(root);
    while (pendingQueue.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingQueue.front();
        pendingQueue.pop();
        if (front->left)
        {
            pendingQueue.push(front->left);
            if (front->right)
            {
                pendingQueue.push(front->right);
                BinaryTreeNode<int> *temp = front->left;
                front->left = front->right;
                front->right = temp;
            }
            else
            {
                front->right = front->left;
                front->left=NULL;
            }
        }else if(front->right){
            pendingQueue.push(front->right);
            front->left=front->right;
            front->right=NULL;
        }

    }
}

void preOrder(BinaryTreeNode <int> * root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";

    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode <int> * root){
    if(root==NULL){
        return;
    }


    postOrder(root->left);
    postOrder(root->right);
    
    cout<<root->data<<" ";
}

void inOrder(BinaryTreeNode <int> * root){
     if(root==NULL){
        return;
    }


    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    
    
}

BinaryTreeNode<int> * constructTreeFromPreNodeInorder(int * inArr,int * preArr,int preS,int preE,int inS,int inE){
    int rootInIndex=0;
    cout<<preE<<endl;
    cout<<preS<<endl;
    for(int i=inS;i<=inE;i++){
        if(inArr[i]==preArr[preS]){
            rootInIndex=i;
            break;
        }
    }


    // cout<<"rootInIndex "<<rootInIndex<<endl;

    BinaryTreeNode<int> * root=new BinaryTreeNode <int> (preArr[preS]);

    if(preE<preS || inE<inS){
        return NULL;
    }


    int leftInS=inS;
    int leftInE=rootInIndex-1;
    int rightInS=rootInIndex+1;
    int rightInE=inE;

    int leftPreS=preS+1;
    int rightPreE=preE;
    int rightPreS=rightPreE-rightInE+rightInS;
    int leftPreE=rightPreS-1;

    root->left=constructTreeFromPreNodeInorder(inArr,preArr,leftPreS,leftPreE,leftInS,leftInE);
    root->right=constructTreeFromPreNodeInorder(inArr,preArr,rightPreS,rightPreE,rightInS,rightInE);

    return root;
}

BinaryTreeNode<int> * constructTreeFromPostNodeInorder(int * poArr, int * inArr,int poS,int poE,int inS,int inE){
    int rootInIndex=0;

    

    for(int i=0;i<=inE;i++){
        if(inArr[i]==poArr[poE]){
            rootInIndex=i;
            break;
        }
    }


    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(poArr[poE]);

    if(poE<poS || inE<inS){
        return NULL;
    }

    int leftPos=poS;
    int rightPoE=poE-1;
    int leftInS=inS;
    int leftInE=rootInIndex-1;
    int rightInS=rootInIndex+1;
    int rightInE=inE;
    int rightPoS=rightPoE-rightInE+rightInS;
    int leftPoE=rightPoS-1;

     root->left=constructTreeFromPostNodeInorder(poArr,inArr,leftPos,leftPoE,leftInS,leftInE);
    root->right=constructTreeFromPostNodeInorder(poArr,inArr,rightPoS,rightPoE,rightInS,rightInE);

    return root;

}

// 10 20 30 40 50 -1 -1 -1 -1 -1 -1
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

int main()
{
    // BinaryTreeNode <int> * root=new BinaryTreeNode<int>(1);
    // BinaryTreeNode <int> * left=new BinaryTreeNode<int>(2);
    // BinaryTreeNode <int> * right=new BinaryTreeNode<int>(3);
    // root->left=left;
    // root->right=right;
    // printTree(root);
    // delete root;
    // BinaryTreeNode<int> *root = takeInputLevelWise();
    // printTree(root);
    // printTreeLevelWise(root);
    // cout<<"No of nodes in tree "<<countNodes(root)<<endl;

    // int x;
    // cout<<"Enter node to found"<<endl;
    // cin>>x;
    // cout<<"node present "<<nodePresent(root,x)<<endl;

    // int mh = 0;
    // cout << heightOfTree(root) << endl;

    // mirrorTree(root);
    // printTreeLevelWise(root);

    // preOrder(root);
    // cout<<endl;
    // postOrder(root);
    // cout<<endl;
    // inOrder(root);
    // cout<<endl;

    // int arr1[7]={1,2,4,5,3,6,7};
    // int arr2[7]={4,2,5,1,6,3,7};
    // BinaryTreeNode<int> * root2=constructTreeFromPreNodeInorder(arr2,arr1,0,6,0,6);
    // printTreeLevelWise(root2);

    

}