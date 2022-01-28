Question Link: https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& newInterval) {
        int ns=newInterval[0], ne=newInterval[1];
        
        vector<vector<int>> ans;
        int n=a.size();
        
        int l=0, r=n-1;
        int idx=n;
        while(l<=r){
            int m=l+(r-l)/2;
            int si=a[m][0], ei=a[m][1];
            
            if(si>=ns){
                idx=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        a.insert(a.begin()+idx,newInterval);
        
        int s=a[0][0], e=a[0][1];
        for(int i=1;i<a.size();i++){
            int si=a[i][0], ei=a[i][1];
            
            if(si>e){
                ans.push_back({s,e});
                s=si;
            }
            e=max(e,ei);
        }
        ans.push_back({s,e});
        
        return ans;
    }
};
