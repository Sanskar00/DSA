#include <iostream>
#include "treeNodeClass.h"
#include <queue>

using namespace std;

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

bool containsx(TreeNode<int> *root, int x)
{
    bool res = root->data == x ? true : false;
    for (int i = 0; i < root->chilren.size(); i++)
    {
        if (res == true)
        {
            return true;
        }
        else
        {
            res = containsx(root->chilren[i], x);
        }
    }

    return res;
}

int countNodesGreaterThenX(TreeNode<int> *root, int x)
{
    int count = 0;

    if (root->data > x)
    {
        count++;
        cout << "count of greater element when root is" << root->data << " " << count << endl;
    }

    for (int i = 0; i < root->chilren.size(); i++)
    {

        count = countNodesGreaterThenX(root->chilren[i], x) + count;
    }

    return count;
}

TreeNode<int> *nodeWithMaxChildSum(TreeNode<int> *root, int &maxSum, TreeNode<int> *res)
{
    int sum = 0;

    for (int i = 0; i < root->chilren.size(); i++)
    {
        sum += root->chilren[i]->data;
    }

    sum = sum + root->data;

    for (int i = 0; i < root->chilren.size(); i++)
    {

        res = nodeWithMaxChildSum(root->chilren[i], maxSum, res);
        cout << maxSum << endl;
        if (maxSum < sum)
        {
            maxSum = sum;
            res = root;
        }
    }

    return res;
}

bool structuallyIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    bool res = root1->data != root2->data ? false : true;
    cout << res << endl;
    for (int i = 0; i < root1->chilren.size(); i++)
    {
        if (res == false)
        {
            return false;
        }
        else if (root1->chilren.size() != root2->chilren.size())
        {
            return false;
        }
        res = structuallyIdentical(root1->chilren[i], root2->chilren[i]);
    }

    return res;
}

void nextLarger(TreeNode<int> *root, int x,int & res)
{
    cout << "root->data " << root->data << endl;
    for (int i = 0; i < root->chilren.size(); i++)
    {

        if (root->chilren[i]->data > x)
        {
            res=root->chilren[i]->data;
            return;
        }
    }
    for (int i = 0; i < root->chilren.size(); i++)
    {
        nextLarger(root->chilren[i], x,res);
    }

}

void helperSecondLarger(TreeNode<int>* root,int & largestElement,int & secondLargestElement){
    if(root->data>largestElement){
        largestElement=root->data;
    }else if(root->data<largestElement && root->data>secondLargestElement){
        secondLargestElement=root->data;
    }

    for(int i=0;i<root->chilren.size();i++){
        helperSecondLarger(root->chilren[i],largestElement,secondLargestElement);
    }
} 

int secondLarger(TreeNode<int> * root){
    int largestElement=0;
    int secondLargestElement=0;
    helperSecondLarger(root,largestElement,secondLargestElement);
    return secondLargestElement;
}

void replaceWithDepth(TreeNode<int> * root,int  k){
    root->data=k;
    

    for(int i=0;i<root->chilren.size();i++){
        replaceWithDepth(root->chilren[i],k+1);
    }


}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 1 9 0
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    // TreeNode<int> *root2=takeInputLevelWise();
    printTreeLevelWise(root);
    // printTreeLevelWise(root2);
    //  cout<<containsx(root,4)<<endl;
    //  cout<<"Count of nodes greater then x "<<countNodesGreaterThenX(root,10)<<endl;
    // int maxSum = 0;
    // cout << nodeWithMaxChildSum(root, maxSum, root)->data << endl;
    // cout<<"Structually identical "<<structuallyIdentical(root1,root2)<<endl;
    // int res=-1;
    // nextLarger(root, 21,res) ;
    // cout<<res<<endl;

    // int secondLargerstElement=secondLarger(root);
    // cout<<"secondLargerstElement "<<secondLargerstElement<<endl;
    replaceWithDepth(root,0);
    printTreeLevelWise(root);
}
