Question Link: https://leetcode.com/problems/strobogrammatic-number-ii/

class Solution {
public:
    void solve(int n, int idx, string s, map<char,char> &mp, vector<string> &ans){
        if(idx==n){
            ans.push_back(s);
            return;
        }
        
        if(idx==0){
            vector<char> v={'1','6','8','9'};
            for(char ch : v){
                solve(n,idx+1,s+ch,mp,ans);
            }
            return;
        }
        if(idx<n/2){
            vector<char> v={'0','1','6','8','9'};
            for(char ch : v){
                solve(n,idx+1,s+ch,mp,ans);
            }
            return;
        }
        if((n%2==1 && (idx==n/2))){
            vector<char> v={'0','1','8'};
            for(char ch : v){
                solve(n,idx+1,s+ch,mp,ans);
            }
            return;
        }
        char ch=s[n-idx-1];
        solve(n,idx+1,s+mp[ch],mp,ans);
    }
    
    vector<string> findStrobogrammatic(int n) {
        if(n==1) return {"0","1","8"};
        
        map<char,char> mp;
        mp['0']='0', mp['1']='1', mp['6']='9', mp['8']='8', mp['9']='6';
        
        vector<string> ans;
        solve(n,0,"",mp,ans);
        
        return ans;
    }
};
