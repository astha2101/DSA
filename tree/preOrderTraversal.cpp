void preOrder(Node *root)
{
  if(root==NULL) return;
  cout<<root->data<<endl;
  preOrder(root->left);
  preOrder(root->right);
}
