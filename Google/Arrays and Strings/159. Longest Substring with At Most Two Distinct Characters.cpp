Question Link: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n=s.length();
        
        int k=2;
        map<char,int> mp;
        int i=0, j=0, maxlen=0;
        
        while(j<n){
            char ch=s[j];
            mp[ch]++;
            
            while(i<=j && mp.size()>k){
                ch=s[i];
                if(--mp[ch]==0) mp.erase(ch);
                i++;
            }
            int len=j-i+1;
            maxlen=max(maxlen,len);
            j++;
        }
        return maxlen;
    }
};
