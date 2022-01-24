Question Link: https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    int expressiveWords(string p, vector<string> &query) {
        int ans=0;
        p += ".";
        for(int k=0;k<query.size();k++){
            string s=query[k]+".";
            
            int n=s.length(), m=p.length();
            int i=0, j=0;
            
            while(i<n-1 && j<m-1){
                if(s[i]!=p[j]) break;
                int c1=1, c2=1;
                
                while(i<n-1 && (s[i]==s[i+1])){
                    c1++, i++;
                }
                while(j<m-1 && (p[j]==p[j+1])){
                    c2++, j++;
                }
                
                if((c1>c2) || (c1!=c2 && c2<=2)) break;
                
                i++, j++;
            }
            ans += (i==n-1 && j==m-1);
        }
        return ans;
    }
};
