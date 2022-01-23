Question Link: https://leetcode.com/problems/container-with-most-water/

// Approach 1:

class Solution {
public:
    int maxArea(vector<int>& a) {
        int n=a.size();
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            int h=a[i], r=i, l=i;
            
            for(int j=i+1;j<n;j++) if(a[j]>=a[i]) r=j;
            for(int j=i-1;j>=0;j--) if(a[j]>=a[i]) l=j;
            
            ans=max(ans,h*(r-l));
        }
        
        return ans;
    }
};

// Approach 2:

class Solution {
public:
    int maxArea(vector<int>& a) {
        int n=a.size();
        
        int ans=0;
        
        int i=0, j=n-1;
        while(i<j){
            ans=max(ans,min(a[i],a[j])*(j-i));
            if(a[j]>a[i]){
                i++;
            }else{
                j--;
            }
        }
         
        return ans; 
    }
};
