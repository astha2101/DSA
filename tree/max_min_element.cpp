class Solution
{
public:
    int findMax(Node *root)
    {
        //code here
        if (root == NULL) return INT_MIN;
        int res=root->data;
        int lres= findMax(root->left);
        int rres= findMax(root->right);
        if(lres>res) res=lres;
        if(rres>res) res=rres;
        return res;
        
    }
    int findMin(Node *root)
    {
        //code here
        if (root == NULL) return INT_MAX;
        int res=root->data;
        int lres= findMin(root->left);
        int rres= findMin(root->right);
        if(lres<res) res=lres;
        if(rres<res) res=rres;
        return res;
    }
};
