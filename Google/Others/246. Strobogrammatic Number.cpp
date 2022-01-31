Question Link: https://leetcode.com/problems/strobogrammatic-number/

class Solution {
public:
    
    bool isStrobogrammatic(string s) {
        map<char,char> mp;
        mp['0']='0', mp['1']='1', mp['6']='9', mp['8']='8', mp['9']='6';
        
        int i=0, j=s.length()-1;
        while(i<=j){
            char ch1=s[i], ch2=s[j];
            if(mp.find(ch1)==mp.end() || mp.find(ch2)==mp.end()) return false;
            if(mp[ch1]!=ch2 || mp[ch2]!=ch1) return false;
            
            i++, j--;
        }
        return true;
    }
};
