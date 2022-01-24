Question Link: https://leetcode.com/problems/find-and-replace-in-string/

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n=s.length(), m=indices.size();
        
        unordered_map<int, pair<int, string>> mp;
        for(int i=0; i<m; i++)
            if(s.substr(indices[i],sources[i].size())==sources[i]){
                mp[indices[i]]={sources[i].size(), targets[i]};
            }
        
        string ans="";
        int i=0;
        while(i<n){
            if(mp.find(i)!=mp.end()){
                ans += mp[i].second;
                i += mp[i].first;
            }else{
                ans+=s[i];
                i++;
            }   
        }
        return ans;
    }
};
