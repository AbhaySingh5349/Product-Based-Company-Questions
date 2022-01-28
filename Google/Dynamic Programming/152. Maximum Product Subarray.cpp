Question Link: https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n=a.size();
        if(n==1) return a[0];
        
        vector<int> pos(n), neg(n);
        
        bool hasPos=false, hasZero=false;
        int count=0;
        
        if(a[0]>0){
            pos[0]=a[0], neg[0]=1;
            hasPos=true;
        }else if(a[0]<0){
            neg[0]=a[0], pos[0]=1;
            count+=(a[0]==-1);
        }else{
            pos[0]=1, neg[0]=1;
            hasZero=true;
        }
        
        int ans=pos[0];
        
        for(int i=1;i<n;i++){
            if(a[i]>0){
                pos[i]=pos[i-1]*a[i];
                neg[i]=(neg[i-1]==1 ? 1:neg[i-1]*a[i]);
                hasPos=true;
            }else if(a[i]<0){
                pos[i]=(neg[i-1]==1 ? 1:neg[i-1]*a[i]);
                neg[i]=pos[i-1]*a[i];
                count+=(a[i]==-1);
            }else{
                pos[i]=1, neg[i]=1;
                hasZero=true;
            }
            
            ans=max(ans,pos[i]);
        }
        
        if(ans==1){
            if(hasPos==true || (count>0 && count%2==0)) return 1;
            if(hasZero==true) return 0;
        }
        return ans;
    }
};
