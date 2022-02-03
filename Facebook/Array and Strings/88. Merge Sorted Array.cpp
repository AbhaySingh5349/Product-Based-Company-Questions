Question Link: https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    
    void reverse(vector<int> &a, int i, int j){
        while(i<j){
            swap(a[i],a[j]);
            i++, j--;
        }
    }
    
    void rotate(vector<int> &a, int k) {
        int n=a.size();   
        
        reverse(a,0,n-1-k);
        reverse(a,n-k,n-1);
        reverse(a,0,n-1);
    }
    
    void merge(vector<int> &a, int m, vector<int> &b, int n) {
        rotate(a,n);
        
        int size=m+n;
        
        int i=n, j=0, k=0;
        while(i<size || j<n){
            int x = (i<size ? a[i]:INT_MAX), y = (j<n ? b[j]:INT_MAX);
            
            if(x<=y){
                a[k++]=x;
                i += (i<size);
            }else{
                a[k++]=y;
                j += (j<n);
            }
        }
    }
};
