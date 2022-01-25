Question Link: https://leetcode.com/problems/trapping-rain-water/

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
