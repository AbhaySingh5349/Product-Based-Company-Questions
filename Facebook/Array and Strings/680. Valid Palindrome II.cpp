Question Link: https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
public:
    
    bool remove(string s, int f){
        int n=s.length();
        int i=0, j=n-1;
        
        while(i<j){
            if(i==f){
                i++;
                continue;
            }
            if(j==f){
                j--;
                continue;
            }
            if(s[i]!=s[j]) return false;
            i++, j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int n=s.length();
        int f1=-1, f2=-1;
        int i=0, j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                f1=i, f2=j;
                break;
            }
            i++, j--;
        }
        if(f1==-1 && f2==-1) return true;
        return (remove(s,f1) || remove(s,f2));
    }
};
