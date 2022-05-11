#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void rightView(Node *root, int level)
{
    static int maxLevel =-1;
    if(root == NULL) return;
    if(maxLevel<level)
    {
        cout<<root->data<<endl;
        cout<<maxLevel<<endl;
        maxLevel = level;
    }
    rightView(root->right,level+1);
    rightView(root->left,level+1);


}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    rightView(root,0);
}
