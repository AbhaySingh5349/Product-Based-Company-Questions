Question Link: https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        
        int i=a.length()-1, j=b.length()-1;
        int carry=0;
        while(i>=0 || j>=0){
            int cur= (i>=0 ? a[i]-'0':0) + (j>=0 ? b[j]-'0':0) + carry;
            
            carry=cur/2;
            
            ans += (cur%2 +'0');
            
            if(i>=0) i--;
            if(j>=0) j--;
        }
        if(carry!=0) ans += (carry+'0');
        
        reverse(ans.begin(),ans.end());
        
        i=0;
        while(ans[i]=='0') i++;
        
        ans = ans.substr(i);
        if(ans.length()==0) ans="0";
        return ans;
    }
};
