class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head,*l1,*l2,*tmp;
        l1=list1;
        l2=list2;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(l1->val>l2->val)
        {
            head = l2;
            l2=l2->next;
        }
        else
        {
            head=l1;
            l1=l1->next;
        }
        tmp=head;
        while(l1 && l2)
        {
            if(l1->val <l2->val)
            {
                tmp->next=l1;
                l1=l1->next;
                tmp=tmp->next;
            }
            else
            {
                tmp->next=l2;
                l2=l2->next;
                tmp=tmp->next;
            }
        }
        while(l1)
        {
            tmp->next=l1;
            l1=l1->next;
            tmp=tmp->next;
        }
        while(l2)
        {
            tmp->next=l2;
            l2=l2->next;
            tmp=tmp->next;
        }
        tmp->next=NULL;
        return head;
    }
};
