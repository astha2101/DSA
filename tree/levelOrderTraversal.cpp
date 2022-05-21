vector<int> result;
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    int _height(Node *node)
    {
        if(node == NULL) return 0;
        int lHeight = _height(node->left);
        int rHeight = _height(node->right);
        
        if(lHeight>rHeight) return lHeight+1;
        else return rHeight+1;
    }
    
    void _levelOrder(Node *root, int level)
    {
        if(root == NULL) return;
        if(level == 1) result.push_back(root->data);
        else
        {
            _levelOrder(root->left,level-1);
            _levelOrder(root->right,level-1);
        }
    }
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      result.clear();
      int height = _height(node);
      for(int i=1;i<=height;i++)
      {
          _levelOrder(node,i);
      }
      return result;
    }
};
