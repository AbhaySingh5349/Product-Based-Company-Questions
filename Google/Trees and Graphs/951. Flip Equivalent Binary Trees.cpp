Question Link: https://leetcode.com/problems/flip-equivalent-binary-trees/

class Solution {
public:
    bool flipEquiv(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        
        if(p->val != q->val) return false;
        
        if(flipEquiv(p->left,q->left)==true && flipEquiv(p->right,q->right)==true){
            return true;
        }else if(flipEquiv(p->left,q->right)==true && flipEquiv(p->right,q->left)==true){
            return true;
        }
        
        return false;
    }
};
