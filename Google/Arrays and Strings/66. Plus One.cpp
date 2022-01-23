Question Link: https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int carry=1, i;
        int n=v.size();
        
        for(i=n-1;i>=0;i--){
            int x=v[i]+carry;
            int r=x%10;
            v[i]=r;
            carry=x/10;
        }
        if(carry!=0){
            v.insert(v.begin(),carry);
        }
        return v;
    }
};
