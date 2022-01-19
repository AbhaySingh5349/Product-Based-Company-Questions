Question Link: https://leetcode.com/problems/license-key-formatting/

class Solution {
public:
    
    char upper(char ch){
        if(ch>='a' && ch<='z') ch=ch-'a'+'A';
        return ch;
    }
    
    string licenseKeyFormatting(string s, int k) {
        string ans="";
        int n=s.length();
        int i=n-1;
        while(i>=0){
            string sub="";
            int x=k;
            while(i>=0 && x>0){
                if(s[i]!='-'){
                    sub += upper(s[i]);
                    x--;
                }
                i--;
            }
            sub += '-';
            ans += sub;
        }
        reverse(ans.begin(),ans.end());
        int len=ans.length();
        while(ans[0]=='-') ans=ans.substr(1);
        
        return ans;
    }
};
