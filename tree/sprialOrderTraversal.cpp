int _height(Node *root)
{
    if(root ==NULL) return 0;
    int lHeight = _height(root->left);
    int rHeight = _height(root->right);
    
    if(lHeight>rHeight)
    {
        return lHeight+1;
    }
    else
    {
        return rHeight+1;
    }
}

void levelOrder(Node *root,int level, bool ltr , vector<int> &res)
{
    if(root==NULL) return;
    if(level == 1)
    {
        res.push_back(root->data);
    }
    else
    {
    if(ltr)
    {
        levelOrder(root->left,level-1,ltr,res);
        levelOrder(root->right,level-1,ltr,res);
    }
    else
    {
        levelOrder(root->right,level-1,ltr,res);
        levelOrder(root->left,level-1,ltr,res);
    }
    }
}
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> res;
    int height = _height(root);
    bool ltr = false;
    for(int i=1;i<=height;i++)
    {
        levelOrder(root,i,ltr,res);
        ltr = !ltr ;
    }
    return res;
}
