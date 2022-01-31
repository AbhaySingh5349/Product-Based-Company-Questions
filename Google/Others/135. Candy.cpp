Question Link: https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int> &a) {
        int n=a.size();
        vector<int> sum(n,1);
        
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1]) sum[i]=sum[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(a[i]>a[i+1]) sum[i]=max(sum[i],sum[i+1]+1);
        }
        
        int ans=accumulate(sum.begin(),sum.end(),0);
        
        return ans;
    }
};
