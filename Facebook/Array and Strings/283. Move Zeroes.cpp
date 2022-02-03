Question Link: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n=a.size();
        
        int i=0, j=0;
        while(j<n){
            while(i<n && a[i]!=0) i++;
            
            j=max(j,i);
            j++;
            if(j<n && a[j]!=0) swap(a[i],a[j]);
        }
    }
};
