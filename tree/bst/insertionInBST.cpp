class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
        {
            TreeNode *root = new TreeNode(val);
            return root;
        }
        TreeNode * newNode = new TreeNode(val);
        TreeNode *prev =NULL;
        TreeNode *temp = root;
        while(root!=NULL)
        {
            if(val<root->val)
            {
                prev = root;
                root = root->left;
            }
            else
            {
                prev = root;
                root = root->right;
            }
        }
        if(val < prev->val)
        {
            prev->left= newNode;
        }
        else
        {
            prev->right = newNode;
        }
        return temp;
    }
};
