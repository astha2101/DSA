void fillMap(Node *root, int dist , map<int,vector<int>> &m)
{
    if(root == NULL) return;
    m[dist].push_back(root->data);
    fillMap(root->left,dist+1,m);
    fillMap(root->right,dist,m);
}


vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> res;
   map<int,vector<int>> m;
   int dist =0;
   fillMap(root,dist,m);
   map<int,vector<int>>::iterator iter = m.begin();
   while(iter!=m.end())
   {
       for(int i=0;i<iter->second.size();i++)
       {
           res.push_back(iter->second[i]);
       }
       ++iter;
   }
   return res;
}
