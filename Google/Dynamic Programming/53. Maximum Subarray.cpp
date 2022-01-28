Question Link: https://leetcode.com/problems/maximum-subarray/

// Approach 1:

class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n=a.size();
        
        int dp[n];
        dp[0]=a[0];
        
        int ans=a[0];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1]+a[i],a[i]);
            ans=max(ans,dp[i]);
        }
        return ans; 
    }
};

// Approach 2:

class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n=a.size();
        
        int ans=a[0];
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=a[i];
            
            ans=max(ans,sum);
            
            if(sum<0) sum=0;
        }
        return ans;
    }
};
