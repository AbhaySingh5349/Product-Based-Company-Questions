Question Link: https://leetcode.com/problems/merge-k-sorted-lists/

class Solution {
public:
    
    ListNode* merge(ListNode* p, ListNode* q) {
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
    
    ListNode* mergeSort(vector<ListNode*> &lists, int s, int e){
        if(s==e) return lists[s];
        
        int m=s+(e-s)/2;
        ListNode* left = mergeSort(lists,s,m);
        ListNode* right = mergeSort(lists,m+1,e);
        
        return merge(left,right);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        
        int n=lists.size()-1;
        return mergeSort(lists,0,n);
    }
};
