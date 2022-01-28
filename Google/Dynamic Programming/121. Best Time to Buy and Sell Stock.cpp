Question Link: https://leetcode.com/problems/trapping-rain-water/

// Approach 1:

class Solution {
public:
    int maxProfit(vector<int> &a) {
        int n=a.size();
        
        int left[n];
        left[0]=a[0];
        for(int i=1;i<n;i++) left[i]=min(left[i-1],a[i]);
        
        int ans=0, right=0;
        for(int i=n-1;i>0;i--){
            right=max(right,a[i]);
            ans=max(ans,right-left[i-1]);
        }
        
        return ans;
    }
};

// Approach 2:

class Solution {
public:
    int maxProfit(vector<int> &a) {
        int n=a.size();
        
        int left=a[0];
        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans,a[i]-left);
            left=min(left,a[i]);
        }
        
        return ans;
    }
};
