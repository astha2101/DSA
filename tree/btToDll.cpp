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

void inorder(Node *root)
{
    if(root== NULL) return;
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

void printList(Node *root)
{
    while(root!=NULL)
    {
        cout<<root->data<<endl;
        root = root->right;
    }
}

void fixLeftPointer(Node *root)
{
    // we will traverse the bt in inorder manner and fix the left pointer of each node.
    static Node *prev = NULL;

    if(root != NULL)
    {
        fixLeftPointer(root->left);
        root->left = prev;
        prev = root;
        fixLeftPointer(root->right);
    }
}

Node * fixRightPointer(Node * root)
{
    // go to the right most node of the tree
    while(root && root->right!= NULL) root = root->right;

    // set the right pointers
    Node *prev = NULL;
    while(root && root->left!=NULL)
    {
        prev = root;
        root = root->left;
        root->right = prev;
    }
    return root;
}

Node *btToDll(Node *root)
{
    fixLeftPointer(root);

    return fixRightPointer(root);
} 
int main()
{
    Node *root = new Node(10);
    root->left= new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    inorder(root);
    printList(btToDll(root));

    return 0;
}
