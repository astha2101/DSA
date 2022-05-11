#include<stack>
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        stack<int> s1,s2,s3;
        Node *temp=first;
        while(temp!=NULL)
        {
            s1.push(temp->data);
            temp=temp->next;
        }
        
        temp=second;
        while(temp!=NULL)
        {
            s2.push(temp->data);
            temp=temp->next;
        }
        
        int carry=0;
        while(!s1.empty() && !s2.empty())
        {
            int x=s1.top();
            int y=s2.top();
            int sum=x+y;
            sum+=carry;
            s3.push(sum%10);
            carry=sum/10;
            s1.pop();
            s2.pop();
            
        }
        
        while(!s1.empty())
        {
            int sum=s1.top()+carry;
            s3.push(sum%10);
            carry=sum/10;
            s1.pop();
        }
        while(!s2.empty())
        {
            int sum=s2.top()+carry;
            s3.push(sum%10);
            carry=sum/10;
            s2.pop();
        }
        
        if(carry==1) s3.push(1);
        
        Node *result = new Node(s3.top());
        s3.pop();
        Node *tmp=result;
        while(!s3.empty())
        {
            tmp->next=new Node(s3.top());
            tmp=tmp->next;
            s3.pop();
        }
        
        return result;
    }
};
