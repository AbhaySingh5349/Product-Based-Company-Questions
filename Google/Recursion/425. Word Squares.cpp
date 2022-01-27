Question Link: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    
    void solve(vector<string> &words, vector<string> &v, int len, map<string,vector<string>> &mp, int maxLen, vector<vector<string>> &ans){
        if(len==maxLen){
            ans.push_back(v);
            return;
        }
        
        string cur="";
        for(int i=0;i<v.size();i++) cur += v[i][len];
        
        if(mp.find(cur)!=mp.end()){
            vector<string> prefix=mp[cur];
            for(int i=0;i<prefix.size();i++){
                v.push_back(prefix[i]);
                solve(words,v,len+1,mp,maxLen,ans);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> wordSquares(vector<string> &words) {
        vector<vector<string>> ans;
        
        map<string,vector<string>> mp;
        for(string word : words){
            for(int j=0;j<word.length();j++){
                string pre=word.substr(0,j);
                mp[pre].push_back(word);
            }
        }
        
        for(int i=0;i<words.size();i++){
            vector<string> v;
            v.push_back(words[i]);
            
            int len=words[i].length();
            solve(words,v,1,mp,len,ans);
        }
        return ans;
    }
};
