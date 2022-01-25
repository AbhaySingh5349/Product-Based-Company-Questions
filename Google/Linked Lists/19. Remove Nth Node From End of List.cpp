Question Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        ListNode *p, *q, *pre;
        pre=NULL;
        p=q=head;
        
        for(int i=0;i<k;i++) q=q->next;
        
        while(q!=NULL){
            pre=p;
            p=p->next;
            q=q->next;
        }
        
        if(pre==NULL) return head->next;
    
        pre->next=p->next;
        
        return head;
    }
};
