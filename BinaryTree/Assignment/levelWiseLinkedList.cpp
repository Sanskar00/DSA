#include <iostream>
#include "btFunctions.h"
#include "BinaryTreeNode.h"
#include <queue>
#include "LinkedListClass.h"
using namespace std;

vector<LinkedList<int> *> levelWIseLinkedList(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    vector<LinkedList<int> *> res;
    q.push(root);
    q.push(NULL);
    LinkedList<int> *head=NULL ;
    LinkedList<int> *tail = NULL;
    while (q.front()!=NULL)
    {
        BinaryTreeNode<int> *front = q.front();
        LinkedList<int> *newNode = new LinkedList<int>(front->data);
        if (head == NULL)
        {
            head = newNode;
            cout<<head->data<<endl;
        }else
        {
            LinkedList<int> *temp = head;
            cout<<"inside else "<<head->data<<endl;
            while (temp->next!=NULL)
            {
                temp = temp->next;
                cout<<"temp data"<<temp->data<<endl;
                cout<<"q front"<<q.front()<<endl;
                q.pop();
            }
            temp->next = newNode;
            
        }
        res.push_back(head);
        if (front->left)
        {
            q.push(front->left);
        }
        if (front->right)
        {
            q.push(front->right);
        }
        if (q.front() == NULL)
        {
            q.pop();
            q.push(NULL);
            head = NULL;
        }
    }
    return res;
}

// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    vector<LinkedList<int> *> vec = levelWIseLinkedList(root);
    cout<<vec.size()<<endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i]->data << endl;
    }
}