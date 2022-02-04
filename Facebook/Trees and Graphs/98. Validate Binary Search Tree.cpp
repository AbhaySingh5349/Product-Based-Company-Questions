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
