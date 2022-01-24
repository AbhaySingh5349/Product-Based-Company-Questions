Question Link: https://leetcode.com/problems/missing-ranges/

class Solution {
public:
    vector<string> findMissingRanges(vector<int> &a, int lower, int upper) {
        a.insert(a.begin(),lower);
        a.push_back(upper);
        
        int n=a.size();
        
        vector<string> ans;
        
        for(int i=1;i<n;i++){
            int lb=a[i-1] + (i==1 ? 0:1), ub=a[i] - (i==n-1 ? 0:1); 
            
            if(lb>ub){
            }else if(lb==ub){
                ans.push_back(to_string(lb));
            }else{
                ans.push_back(to_string(lb)+"->"+to_string(ub));
            }
        }
        return ans;
    }
};  
