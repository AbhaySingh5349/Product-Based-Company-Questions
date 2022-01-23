Question Link: https://leetcode.com/problems/multiply-strings/

class Solution {
public:
    string mul(string s, int d){
        int n=s.length();
        int i=n-1;
        int carry=0;
        string ans="";
        while(i>=0){
            int last=(s[i]-'0')*d+carry;
            ans.insert(ans.begin(),last%10 + '0');
            carry=last/10;
            i--;
        }
        if(carry!=0) ans.insert(ans.begin(),carry%10 + '0');
        return ans;
    }
    
    void addZeroes(string &s, int zero){
        for(int i=0;i<zero;i++) s+="0";
    }
    
    string addStrings(string &s1, string &s2){
        int n=s1.length(), m=s2.length();
        string ans="";
        int i=n-1, j=m-1;
        int carry=0;
        while(i>=0 || j>=0){
            int last=(i>=0 ? s1[i]-'0':0) + (j>=0 ? s2[j]-'0':0) + carry;
            ans.insert(ans.begin(),last%10 + '0');
            carry=last/10;
            
            if(i>=0) i--;
            if(j>=0) j--;
        }
        if(carry!=0) ans.insert(ans.begin(),carry%10 + '0');
        return ans;
    }
    
    string multiply(string a, string b) {
        int n=a.length(), m=b.length();
        int i=m-1;
        int zero=0;
        string res="";
        while(i>=0){
            int d=b[i]-'0';
            string sub=mul(a,d);
            
            if(res.length()==0){
                res=sub;
            }else{
                addZeroes(sub,zero);
                res=addStrings(res,sub);
            }
            zero++;
            i--;
        }
        while(res[0]=='0') res.erase(res.begin());
        
        return (res.length()==0 ? "0":res);  
    }
};
