Question Link: https://leetcode.com/problems/validate-binary-search-tree/

// Approach 1:

class Solution {
public:
    
    #define ll long long 
    
    struct Info{
        bool isBST;
        ll int submax;
        ll int submin;
    };
    
    ll getMax(ll int a, ll int b){
        if(a>=b) return a;
        return b;
    }
    
    ll getMin(ll int a, ll int b){
        if(a>b) return b;
        return a;
    }
    
    Info check(TreeNode* root){
        if(root==NULL) return {true,LONG_MIN,LONG_MAX};
        
        Info leftInfo=check(root->left);
        Info rightInfo=check(root->right);
        
        int val=root->val;
        bool curBST=(val>leftInfo.submax && val<rightInfo.submin && leftInfo.isBST && rightInfo.isBST);
        
        ll int curmax=getMax(val,max(leftInfo.submax,rightInfo.submax));
        ll int curmin=getMin(val,min(leftInfo.submin,rightInfo.submin));
        
        Info cur={curBST,curmax,curmin};
        return cur;
    }
    
    bool isValidBST(TreeNode* root) {
        if((root==NULL) || (root->left==NULL && root->right==NULL)) return true;
        return check(root).isBST;
    }
};

// Approach 2:

class Solution {
public:
    #define ll long long 
    
    struct Info{
        bool isBST;
        ll int submax;
        ll int submin;
        Info(bool valid,ll int maxval, ll int minval){
            isBST=valid;
            submax=maxval;
            submin=minval;
        }
    };
    
    ll getMax(ll int a, ll int b){
        if(a>=b) return a;
        return b;
    }
    
    ll getMin(ll int a, ll int b){
        if(a>b) return b;
        return a;
    }
    
    Info check(TreeNode* root){
        if(root==NULL) return {true,LONG_MIN,LONG_MAX};
        
        Info leftInfo=check(root->left);
        Info rightInfo=check(root->right);
        
        int val=root->val;
        bool curBST=(val>leftInfo.submax && val<rightInfo.submin && leftInfo.isBST && rightInfo.isBST);
        
        ll int curmax=getMax(val,max(leftInfo.submax,rightInfo.submax));
        ll int curmin=getMin(val,min(leftInfo.submin,rightInfo.submin));
        
        Info cur={curBST,curmax,curmin};
        return cur;
    }
    
    bool isValidBST(TreeNode* root) {
        if((root==NULL) || (root->left==NULL && root->right==NULL)) return true;
        return check(root).isBST;
    }
};

// Approach 3:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool isValid(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) return true;
        if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        return isValid(root->left, minNode, root) && isValid(root->right, root, maxNode);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValid(root,NULL,NULL);
    }
};
