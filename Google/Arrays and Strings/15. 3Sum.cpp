Question Link: https://leetcode.com/problems/3sum/

class Solution {
public:
    
    void solve(vector<int> &a, vector<vector<int>> &ans, int k, int i, int j, int val){
        while(i<j){
            int sum=a[i]+a[j];
            
            if(sum<k){
                i++;
            }else if(sum>k){
                j--;
            }else{
                ans.push_back({val,a[i],a[j]});
                i++, j--;
                
                while(i<=j && a[i]==a[i-1]) i++;
                while(i<=j && a[j]==a[j+1]) j--;
            }
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& a) {
        int n=a.size();
        
        vector<vector<int>> ans;
        if(n<3) return ans;
        
        sort(a.begin(),a.end());
        
        int k=0, i=0;
        while(i<n){
            solve(a,ans,k-a[i],i+1,n-1,a[i]);
            i++;
            while(i<n && a[i]==a[i-1]) i++;
        }
        
        return ans;
    }
};
