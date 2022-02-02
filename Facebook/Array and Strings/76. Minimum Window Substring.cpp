Question Link: https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string p) {
        int n=s.length(), m=p.length();
        
        map<char,int> pm;
        for(int i=0;i<m;i++) pm[p[i]]++;
        
        map<char,int> sm;
        
        int minlen=n+1, si=-1, ei=-1;
        int c=0, i=0, j=0;
        
        while(j<n){
            char ch=s[j];
            sm[ch]++;
            
            if(pm.find(ch)!=pm.end()){
                if(sm[ch]<=pm[ch]) c++;
            }
            
            while(i<=j && c==m){
                int len=j-i+1;
                if(len<minlen){
                    minlen=len;
                    si=i, ei=j;
                }
                ch=s[i];
                sm[ch]--;
                
                if(pm.find(ch)!=pm.end()){
                    if(sm[ch]<pm[ch]) c--;
                }
                if(sm[ch]==0) sm.erase(ch);
                i++;
            }
            j++;
        }
        string ans="";
        if(minlen<n+1){
            for(int i=si;i<=ei;i++) ans+=s[i];
        }
        
        return ans;
    }
};
