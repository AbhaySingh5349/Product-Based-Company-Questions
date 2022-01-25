Question Link: https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    
    int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    
    void solve(vector<vector<char>> &grid, int i, int j){
        int n=grid.size(), m=grid[0].size();
        
        if(i<0 || j<0 || i==n || j==m || grid[i][j]!='1') return ;
        
        grid[i][j]='*';
        for(int k=0;k<4;k++){
            int x=i+dxy[k][0], y=j+dxy[k][1];
            solve(grid,x,y);
        }
    }
    
    int numIslands(vector<vector<char>> &grid) {
        int n=grid.size(), m=grid[0].size();
        
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    c++;
                    solve(grid,i,j);
                }
            }
        }
        return c;
    }
};
