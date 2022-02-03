Question Link: https://leetcode.com/problems/one-edit-distance/

class Solution {
public:
    
    bool isOneEditDistance(string s, string p) {
        int n=s.length(), m=p.length();
        
        if(n>m) return isOneEditDistance(p,s);
        
        if(m-n>1) return false;
        
        for(int i=0;i<n;i++){
            if(s[i]!=p[i]){
                if(n==m){
                    return (s.substr(i+1)==p.substr(i+1));
                }else{
                    return (s.substr(i)==p.substr(i+1));
                }
            }
        }
        return (n+1 == m);
    }
};
