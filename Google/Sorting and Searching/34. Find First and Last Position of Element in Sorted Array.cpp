Question Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    
    int lb(vector<int>& a, int target){
        int n=a.size();
        int idx=-1;
        int l=0, r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(a[m]==target){
                idx=m;
                r=m-1;
            }else if(a[m]>target){
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return idx;
    }
    
    int ub(vector<int>& a, int target){
        int n=a.size();
        int idx=-1;
        int l=0, r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(a[m]==target){
                idx=m;
                l=m+1;
            }else if(a[m]<target){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return idx;
    }
    
    vector<int> searchRange(vector<int>& a, int target) {
        int first=lb(a,target);
        if(first==-1) return {-1,-1};
        int last=ub(a,target);
        return {first,last};
    }
};
