Question Link: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    
    void getPalondrome(string s, int l, int r, int &maxlen, int &start){
        int n=s.length();
        while(l>=0 && r<n && s[l]==s[r]){
            int len=r-l+1;
            if(len>maxlen){
                maxlen=len;
                start=l;
            }
            l--, r++;
        }
    }
    
    string longestPalindrome(string s) {
        int n=s.length();
        
        int maxlen=0, start=-1;
        for(int i=0;i<n;i++){
            int l, r;
            
            getPalondrome(s,i,i,maxlen,start); // odd length
            
            getPalondrome(s,i,i+1,maxlen,start); // even length
        }
        
        string ans="";
        for(int i=start;i<start+maxlen;i++) ans+=s[i];
        
        return ans;
    }
};
