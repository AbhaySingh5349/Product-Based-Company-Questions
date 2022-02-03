Question Link: https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &a) {
        int n=a.size();
        
        vector<int> left(n,1), right(n,1);
        
        for(int i=1;i<n;i++) left[i]=left[i-1]*a[i-1];
        for(int i=n-2;i>=0;i--) right[i]=right[i+1]*a[i+1];
        
        vector<int> ans;
        for(int i=0;i<n;i++) ans.push_back(left[i]*right[i]);
        
        return ans;
    }
};
