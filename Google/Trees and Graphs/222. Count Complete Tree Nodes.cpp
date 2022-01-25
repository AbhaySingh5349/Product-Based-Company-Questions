Question Link: https://leetcode.com/problems/count-complete-tree-nodes/

class Solution {
public:
    
    int depth(TreeNode* root){
        int d=0;
        while(root!=NULL){
            d++;
            root=root->left;
        }
        return d;
    }
    
    int power(int a, int b){
        if(b==0) return 1;
        if(b%2==0) return power(a*a,b/2);
        return a*power(a,b-1);
    }
    
    bool possible(TreeNode* p, int mid, int d){
        int l=1, r=power(2,d-1);
        while(l<r){
            int m=l+(r-l)/2;
            if(mid<=m){
                r=m;
                p=p->left;
            }else{
                p=p->right;
                l=m+1;
            }
        }  
        return (p!=NULL);
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        
        int d=depth(root);
        if(d==1) return 1;
        
        int l=1, r=power(2,d-1);
        while(l<r){
            int m=l+(r-l+1)/2;
            if(possible(root,m,d)){
                l=m;
            }else{
                r=m-1;
            }
        }
        
        return (power(2,d-1)-1 + l);
    }
};
