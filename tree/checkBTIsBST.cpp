class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBSTUtil(Node *root, Node * &prev)
    {
        if(root)
        {
            if(!isBSTUtil(root->left,prev)) return false;
            
            if(prev!=NULL && root->data <= prev->data) return false;
            
            prev = root;
            
            return isBSTUtil(root->right,prev);
        }
        
        return true;
    }
    bool isBST(Node* root) 
    {
        // Your code here
        Node *prev = NULL;
        return isBSTUtil(root,prev);
    }
};
