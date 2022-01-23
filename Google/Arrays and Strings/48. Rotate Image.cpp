Question Link: https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& grid) {
        int n=grid.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++) swap(grid[i][j],grid[j][i]);
        }
        
        for(int k=0;k<n;k++){
            int i=0, j=n-1;
            while(i<j){
                swap(grid[k][i],grid[k][j]);
                i++, j--;
            }
        }
    }
};
