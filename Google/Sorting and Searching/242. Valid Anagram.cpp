Question Link: https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string p) {
        int n=s.length(), m=p.length();
        if(n!=m) return false;
        
        vector<int> sm(26,0), pm(26,0);
        
        for(int i=0;i<n;i++) sm[s[i]-'a']++;
        for(int i=0;i<m;i++) pm[p[i]-'a']++;
        
        for(int i=0;i<26;i++) if(sm[i]!=pm[i]) return false;
        
        return true;
    }
};
