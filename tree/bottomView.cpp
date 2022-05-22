
class Solution {
    
  public:
    void fillMap(Node *root,int vd,int level,map<int,pair<int,int>> &m)
    {
        if(root ==NULL) return;
        if(m.count(vd) == 0)
        {
            m[vd] = make_pair(root->data,level);
        }
        else if(m[vd].second <= level)
        { 
            m[vd] = make_pair(root->data,level);
        }
        fillMap(root->left,vd-1,level+1,m);
        fillMap(root->right,vd+1,level+1,m);
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> res;
        map<int,pair<int,int>> m;
        int vd =0;
        int level =0;
        fillMap(root,vd,level,m);
        map<int,pair<int,int>>::iterator iter = m.begin();
        while(iter!=m.end())
        {
            res.push_back(iter->second.first);
            ++iter;
        }
        return res;
    }
};
