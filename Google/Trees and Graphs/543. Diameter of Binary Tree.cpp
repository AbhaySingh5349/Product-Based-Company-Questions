Question Link: https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    
    struct node{
        int NTL;
        int LTL;
    };
    
    struct node solve(TreeNode* root){
        if(root==NULL) return {-1,-1};
        
        struct node leftNode=solve(root->left);
        struct node rightNode=solve(root->right);
        
        int curNTL = max(leftNode.NTL,rightNode.NTL)+1;
        int curLTL = max(leftNode.NTL+rightNode.NTL+2,max(leftNode.LTL,rightNode.LTL));
        
        struct node curNode = {curNTL,curLTL};
        return curNode;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).LTL;
    }
};
