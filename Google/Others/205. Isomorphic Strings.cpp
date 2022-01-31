Question Link: https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string p) {
        int n=s.length(), m=p.length();
        
        if(n!=m) return false;
        
        map<char,char> mp;
        set<char> st;
        
        for(int i=0;i<n;i++){
            char ch1=s[i], ch2=p[i];
            
            if(mp.find(ch1)==mp.end()){
                if(st.find(ch2)!=st.end()) return false;
                mp[ch1]=ch2;
                st.insert(ch2);
            }else{
                if(mp[ch1]!=ch2) return false;
            }
        }
        return true;
    }
};
