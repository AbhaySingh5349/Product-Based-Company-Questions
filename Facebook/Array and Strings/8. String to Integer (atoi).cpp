Question Link: https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        
        int i=0, sign=2;
        long num=0;
        
        while(i<n){
            if(s[i]==' '){
                
            }else if(s[i]=='+'){
                if(sign!=2 || !isdigit(s[i+1])) return 0;
                sign=1;
            }else if(s[i]=='-'){
                if(sign!=2 || !isdigit(s[i+1])) return 0;
                sign=-1;
            }else if(isalpha(s[i])){
                return 0;
            }else{
                while(isdigit(s[i])){
                    num = num*10 + (s[i]-'0');
                    i++;
                    
                    if(num>INT_MAX) return (sign==-1 ? INT_MIN:INT_MAX);
                }
                if(sign==2) sign=1;
                num*=sign;
                
                return num;
            }
            i++;
        }
        return 0;
    }
};
