Question Link: https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int> &a, int k) {
        int n=a.size();
        
        map<int,int> mp;
        int sum=0, ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum += a[i];
            int target = sum-k;
            if(mp.find(target)!=mp.end()) ans += mp[target];
            
            mp[sum]++;
        }
        return ans;
    }
};
