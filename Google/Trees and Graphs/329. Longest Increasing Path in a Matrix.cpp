Question Link: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<int>> memo;
    
    int solve(vector<vector<int>>& grid, int i, int j){
        int n=grid.size(), m=grid[0].size();
        if(memo[i][j]!=-1) return memo[i][j];
        int ans=1;
        for(int k=0;k<4;k++){
            int x=i+dxy[k][0], y=j+dxy[k][1];
            if(x>=0 && y>=0 && x<n && y<m && grid[x][y]>grid[i][j]){
                int len=1+solve(grid,x,y);
                ans=max(ans,len);
            }
        }
        return memo[i][j]=ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int ans=1;
        
        memo.resize(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,solve(grid,i,j));
            }
        }
        return ans;
    }
};
