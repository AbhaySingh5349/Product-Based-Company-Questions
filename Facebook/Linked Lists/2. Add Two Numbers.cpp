Question Link: https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        int carry=0;
        struct ListNode *head, *last;
        head=last=new ListNode(-1);
        
        while(l1 || l2){
            int d = (l1!=NULL ? l1->val:0) + (l2!=NULL ? l2->val:0) + carry;
            int r=d%10;
            carry=d/10;
            
            last->next=new ListNode(r);
            last=last->next;
            
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(carry!=0) last->next = new ListNode(carry);
        return head->next;
    }
};
