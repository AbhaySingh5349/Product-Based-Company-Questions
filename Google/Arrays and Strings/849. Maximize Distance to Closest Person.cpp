Question Link: https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    int maxDistToClosest(vector<int> &a) {
        int n=a.size();
        
        int ans=0;
        int prev=-1;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                ans = (prev==-1 ? i:max(ans,(i-prev)/2));
                prev=i;
            }
        }
        ans=max(ans,n-1-prev);
        return ans;
    }
};
