class Compare
{
    public:
    bool operator()(ListNode *l1,ListNode *l2)
    {
        if(l1==NULL) return false;
        if(l2==NULL) return true;
        
        return l1->val > l2->val;
    }
    
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode *, vector<ListNode *>,Compare> minHeap;
       for(auto node : lists)
       {
           minHeap.push(node);
       }
        ListNode *head=NULL;
        ListNode *curr=NULL;
        while(!minHeap.empty())
        {
            ListNode *node = minHeap.top();
            minHeap.pop();
            if(head==NULL)
            {
                head=node;
                curr=node;
            }
            else
            {
                curr->next=node;
                curr=node;
            }
            if(node && node->next!=NULL)
            {
                minHeap.push(node->next);
            }
        }
        return head;
    }
};


/*
Time complexity: -max(klogk,NlogK)
space complexity :- O(k);
/*
