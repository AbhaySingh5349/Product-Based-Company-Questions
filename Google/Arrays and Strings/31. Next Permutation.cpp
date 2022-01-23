Question Link: https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& v) {
        bool isSorted = true;
        int n = v.size(), i;
        for(i=1;i<n;i++){
            if(v[i]>v[i-1]){
                isSorted=false;
                break;
            }
        }
        if(isSorted) return reverse(v.begin(), v.end());
        
        i=n-1;
        while(i>0 && v[i]<=v[i-1]) i--;
        int pos1 = i-1, pos2=i;

        for(i=pos2+1;i<n;i++){
            if(v[i]>v[pos1] && v[i]<v[pos2]){
                pos2=i;
            }
        }
        swap(v[pos1],v[pos2]);
        sort(v.begin() + pos1+1,v.end());
    }
};
