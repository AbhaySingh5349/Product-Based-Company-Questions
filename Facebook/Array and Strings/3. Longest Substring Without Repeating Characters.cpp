Question Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        
        map<char,int> mp;
        
        int c=0, i=0, j=0;
        
        int maxlen=0;
        while(j<n){
            char ch=s[j];
            mp[ch]++;
            c++;
            
            while(c>mp.size()){
                ch=s[i];
                i++;
                if(--mp[ch]==0) mp.erase(ch);
                c--;
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};
