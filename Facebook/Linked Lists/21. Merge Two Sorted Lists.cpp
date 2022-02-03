Question Link: https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* p, ListNode* q) {
        ListNode *head, *last;
        head=last=new ListNode(-1);
        
        while(p!=NULL || q!=NULL){
            int x=(p!=NULL ? p->val:INT_MAX);
            int y=(q!=NULL ? q->val:INT_MAX);
            
            if(x>y){
                last->next = new ListNode(y);
                q=q->next;
            }else{
                last->next = new ListNode(x);
                p=p->next;
            }
            last=last->next;
        }
        
        return head->next;
    }
};
