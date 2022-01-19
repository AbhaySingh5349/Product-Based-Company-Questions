Question Link: https://leetcode.com/problems/unique-email-addresses/

class Solution {
public:
    int numUniqueEmails(vector<string> &emails) {
        map<string,bool> mp;
        int c=0;
        for(int i=0;i<emails.size();i++){
            string s=emails[i], sub="";
            
            int j=0, n=s.length();
            bool found=false;
            while(j<n){
                if(s[j]=='.'){
                    if(found) sub += s[j];
                }else if(s[j]=='+' && found==false){
                    string suf=s.substr(j+1);
                    string domain=suf.substr(suf.find('@'));
                    
                    sub += domain;
                    break;
                }else{
                    if(s[j]=='@') found=true;
                    sub += s[j];
                }
                j++;
            }
            if(mp.find(sub)==mp.end()) c++;
            mp[sub]=true;
        }
        return c;
    }
};
