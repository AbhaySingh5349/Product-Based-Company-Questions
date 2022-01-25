Question Link: https://leetcode.com/problems/backspace-string-compare/

// Approach 1:

class Solution {
public:
    
    string update(string s){
        int n=s.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(isalpha(ch)){
                st.push(ch);
            }else{
                if(st.size()>0) st.pop();
            }
        }
        
        string ans="";
        while(st.size()>0){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    bool backspaceCompare(string s, string t) {
        return (update(s)==update(t));
    }
};

// Approach 2:

class Solution {
public:
    
    bool backspaceCompare(string s, string t) {
        int n=s.length(), m=t.length();
        int i=n-1, j=m-1, cs=0, ct=0;
        
        while(i>=0 || j>=0){
            while(i>=0){
                if(s[i]=='#'){
                    cs++, i--;
                }else if(cs>0){
                    cs--, i--;
                }else{
                    break;
                }
            }
            while(j>=0){
                if(t[j]=='#'){
                    ct++, j--;
                }else if(ct>0){
                    ct--, j--;
                }else{
                    break;
                }
            }
            if(i>=0 && j>=0 && s[i]!=t[j]) return false;
            if((i>=0) != (j>=0)) return false;
            
            i--, j--;
        }
        return true;
    }
};
