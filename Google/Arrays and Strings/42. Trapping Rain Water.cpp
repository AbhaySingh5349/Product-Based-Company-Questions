Question Link: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        
        vector<int> left(n,0), right(n,0);
        
        for(int i=1;i<n;i++) left[i]=max(left[i-1],a[i-1]);
        for(int i=n-2;i>=0;i--) right[i]=max(right[i+1],a[i+1]);
        
        int ans=0;
        for(int i=1;i<n-1;i++){
            ans+=max(0,min(left[i],right[i])-a[i]);
        }
        return ans;
    }
};
