Question Link: https://leetcode.com/problems/trapping-rain-water/

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
