Question Link: https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
public:
    vector<vector<int>> grid;
    NumMatrix(vector<vector<int>> &mat) {
        int n=mat.size(), m=mat[0].size();
        
        grid.resize(n,vector<int>(m,0));
        
        grid[0][0]=mat[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=mat[i][j];
                
                if(i>0) grid[i][j] += grid[i-1][j];
                if(j>0) grid[i][j] += grid[i][j-1];
                if(i>0 && j>0) grid[i][j] -= grid[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int ans=grid[r2][c2];
        
        if(r1>0) ans -= grid[r1-1][c2];
        if(c1>0) ans -= grid[r2][c1-1];
        if(r1>0 && c1>0) ans += grid[r1-1][c1-1];
        
        return ans;
    }
};
