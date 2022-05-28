
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head ==NULL) return head;
        Node *curr, *temp;
        curr=head;
        while(curr)
        {
            temp=curr->next;
            curr->next= new Node(curr->val);
            curr->next->next=temp;
            curr=temp;
        }
        curr=head;
        while(curr)
        {
            if(curr->next)
            {
                curr->next->random = curr->random? curr->random->next:curr->random;
            }
            curr=curr->next?curr->next->next:curr->next;
            
        }
        Node *org,*copy;
        org=head;
        copy=head->next;
        temp=copy;
        while(org && copy)
        {
            org->next = org->next?org->next->next:org->next;
            copy->next = copy->next?copy->next->next: copy->next;
            org=org->next;
            copy=copy->next;
        }
        return temp;
        
    }
};

/*
Time complexity : O(n)
*/
