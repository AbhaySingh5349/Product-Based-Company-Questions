Question Link: https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        int m=v.size();
        
        map<map<char,int>,vector<string>> bm;
        
        for(int i=0;i<m;i++){
            map<char,int> sm;
            
            string s=v[i];
            int n=s.length();
            
            for(int i=0;i<n;i++){
                char ch=s[i];
                sm[ch]++;
            }
            
            vector<string> cur;
            if(bm.find(sm)!=bm.end()) cur=bm[sm];
            cur.push_back(s);
            
            bm[sm]=cur;
        }
        
        vector<vector<string>> ans;
            
        map<map<char,int>,vector<string>> :: iterator it;
        for(it=bm.begin();it!=bm.end();it++){
            vector<string> cur=it->second;
            
            ans.push_back(cur);
        }
        
        return ans;
    }
};
