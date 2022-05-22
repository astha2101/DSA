class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,vector<int>> verticalOrderMap;
        vector<int> res;
        int hd = 0;
        queue<pair<Node *,int>> q;
        q.push(pair<Node *,int>(root,hd));
        while(!q.empty())
        {
            pair<Node *,int> temp = q.front();
            q.pop();
            hd = temp.second;
            Node * node = temp.first;
            verticalOrderMap[hd].push_back(node->data);
            if(node->left!=NULL)
            {
                q.push(pair<Node *,int>(node->left,hd-1));
            }
            if(node->right!=NULL)
            {
                q.push(pair<Node *,int>(node->right,hd+1));
            }
        }
        
        map<int,vector<int>>:: iterator iter = verticalOrderMap.begin();
        while(iter != verticalOrderMap.end())
        {
            for(int i=0;i<iter->second.size();i++)
            {
                res.push_back(iter->second[i]);
            }
            iter++;
        }
        return res;
    }
        
};
/*
Time complexity : - O(nlogn)
Space complexity : - O(n)
*/
