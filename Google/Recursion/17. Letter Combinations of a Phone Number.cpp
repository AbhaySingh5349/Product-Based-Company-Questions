Question Link: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    
    vector<vector<char>> v={{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},
                                {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    
    void solve(string digits, int idx, string s , vector<string> &ans){
        int n=digits.length();
        if(idx==n){
            ans.push_back(s);
            return;
        }
        
        int dig=digits[idx]-'0';
        for(char ch : v[dig]){
            solve(digits,idx+1,s+ch,ans);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        
        vector<string> ans;
        
        solve(digits,0,"",ans);
        
        return ans;
    }
};
