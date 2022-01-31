Question Link: https://leetcode.com/problems/coin-change/

// Approach 1:

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

// Approach 2:

class Solution {
public:
    int coinChange(vector<int> &a, int k) {
        int n=a.size();
        
        vector<vector<int>> dp(n+1,vector<int>(k+1,INT_MAX/2));
        for(int j=0;j<k+1;j++) dp[0][j]=INT_MAX/2;
        for(int i=0;i<n+1;i++) dp[i][0]=0;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<k+1;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=a[i-1] && dp[i][j-a[i-1]]!=INT_MAX/2) dp[i][j] = min(dp[i][j],1+dp[i][j-a[i-1]]);
            }
        }
        
        return (dp[n][k]>=INT_MAX/2 ? -1:dp[n][k]);
    }
};
