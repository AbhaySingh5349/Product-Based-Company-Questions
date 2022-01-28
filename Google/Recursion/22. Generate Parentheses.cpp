Question Link: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    
    void solve(int open, int close, string s, vector<string> &ans){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        
        if(open==close){
            solve(open-1,close,s+'(',ans);
        }else{
            if(open>0) solve(open-1,close,s+'(',ans);
            if(close>0) solve(open,close-1,s+')',ans);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        solve(n,n,"",ans);
        
        return ans;
    }
};
