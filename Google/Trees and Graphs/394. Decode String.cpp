Question Link: https://leetcode.com/problems/decode-string/

// Approach 1:

class Solution {
public:
    
    string getSub(stack<char> &st){
        string sub="";
        while(st.size()>0 && st.top()!='['){
            sub += st.top();
            st.pop();
        }
        st.pop();
        reverse(sub.begin(),sub.end());
        
        return sub;
    }
    
    int getFactor(stack<char> &st){
        int k=0, base = 1;
        while(st.size()>0 && isdigit(st.top())){
            k = k + (st.top()-'0')*base;
            st.pop();
            base*=10;
        }
        
        return k;
    }
    
    string decodeString(string s) {
        int n=s.length();
        
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]==']'){
                string sub=getSub(st);
                int k=getFactor(st);
                
                string update="";
                while(k--) update += sub;
                for(int j=0;j<update.length();j++) st.push(update[j]);
            }else{
                st.push(s[i]);
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
};

// Approach 2:

class Solution {
public:
    
    string solve(string s, int &i){
        string ans="";
        
        int n=s.length();
        
        while(i<n && s[i]!=']'){
            
            if(isdigit(s[i])){
                int k=0;
                while(i<n && isdigit(s[i])) k = k*10 + (s[i++]-'0');

                i++; // skipping '['

                string sub=solve(s,i);
                
                i++; // skipping ']'
                
                while(k--) ans += sub;
            }else{
                ans += s[i++];
            }
        } 
        return ans;
    }
    
    string decodeString(string s) {
        int i=0;
        return solve(s,i);
    }
};
