Question Link: https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    
    bool check(char ch, char top){
        return ((top=='(' && ch==')') || (top=='[' && ch==']') || (top=='{' && ch=='}'));
    }
    
    bool isValid(string s) {
        int n=s.length();
        
        stack<char> st;
        for(int i=0;i<n;i++){
            char ch=s[i];
            
            if(ch=='(' || ch=='[' || ch=='{'){
                st.push(ch);
            }else{
                if(st.size()==0 || check(ch,st.top())==false) return false;
                st.pop();
            }
        }
        return (st.size()==0);
    }
}; 
