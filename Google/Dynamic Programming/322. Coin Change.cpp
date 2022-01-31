Question Link: https://leetcode.com/problems/coin-change/

class Solution {
public:
    
    vector<vector<int>> memo;
    
    int solve(vector<int> &a, int k, int idx){
        int n=a.size();
        if(k==0) return 0;
        if(idx==n) return INT_MAX/2;
        
        if(memo[idx][k]!=-1) return memo[idx][k];
        
        int ans=INT_MAX/2;
        
        if(k>=a[idx]) ans=min(ans,1+solve(a,k-a[idx],idx));
        ans=min(ans,solve(a,k,idx+1));
        
        return memo[idx][k]=ans;
    }
    
    int coinChange(vector<int> &a, int k) {
        int n=a.size();
        memo.resize(n,vector<int> (k+1,-1));
        
        int ans=solve(a,k,0);
        
        return (ans>=INT_MAX/2 ? -1:ans);
    }
};
