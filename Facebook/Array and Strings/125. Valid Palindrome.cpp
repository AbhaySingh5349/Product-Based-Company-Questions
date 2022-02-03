Question Link: https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    
    char lower(char ch){
        if(ch>='A' && ch<='Z') ch=ch-'A'+'a';
        return ch;
    }
    
    bool isPalindrome(string s) {
        int n=s.length();
        int i=0, j=n-1;
        
        while(i<j){
            
            while(i<j && !isdigit(s[i]) && !isalpha(s[i])) i++;
            while(i<j && !isdigit(s[j]) && !isalpha(s[j])) j--;
            
            if(i>=j) return true;
            
            char ch1=lower(s[i]);
            char ch2=lower(s[j]);
            
            if(ch1!=ch2) return false;
            i++, j--;
        }
        return true;
    }
};
