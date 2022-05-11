class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node *curr=head;
        node *prev=NULL, *next=NULL;
        for(int i=0;i<k && curr!=NULL;i++)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        if(next!=NULL)
        {
            head->next=reverse(next,k);
        }
        return prev;
    }
};
