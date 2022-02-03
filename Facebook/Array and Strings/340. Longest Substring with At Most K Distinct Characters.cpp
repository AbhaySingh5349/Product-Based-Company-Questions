Question Link: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n=s.length();
        int i=0, j=0;
        
        map<char,int> mp;
        int ans=0;
        while(j<n){
            char ch=s[j];
            mp[ch]++;
            
            while(i<=j && mp.size()>k){
                ch=s[i];
                if(--mp[ch]==0) mp.erase(ch);
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
