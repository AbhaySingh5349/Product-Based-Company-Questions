Question Link: https://leetcode.com/problems/number-of-islands/

// Approach 1:

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

// Approach 2:

class Solution {
public:
    
    int dxy[2][2]={{-1,0},{0,-1}};
    
    int find(int u, vector<int> &parent){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u],parent);
    }
    void merge(int pu, int pv, vector<int> &parent, vector<int> &rk){
        if(rk[pu]>rk[pv]){
            rk[pu]+=rk[pv];
            parent[pv]=pu;
        }else{
            rk[pv]+=rk[pu];
            parent[pu]=pv;
        } 
    }
    
    int numIslands(vector<vector<char>> &grid) {
        int n=grid.size(), m=grid[0].size();
        
        vector<int> parent(n*m), rk(n*m,0);
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int id=i*m+j;
                if(grid[i][j]=='1'){
                    parent[id]=id;
                    rk[id]=1;
                    c++;
                }else{
                    parent[id]=-1;
                    rk[id]=0;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    for(int k=0;k<2;k++){
                        int x=i+dxy[k][0], y=j+dxy[k][1];
                        if(x>=0 && y>=0 && x<n && y<m && grid[x][y]=='1'){
                            int u=i*m+j, v=x*m+y;
                            int pu=find(u,parent), pv=find(v,parent);
                            if(pu!=pv){
                                merge(pu, pv, parent, rk);
                                c--;
                            }
                        }
                    } 
                    
                }
            }
        }
        return c;
    }
};

// Approach 3:

class Solution {
public:
    
    int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    
    int numIslands(vector<vector<char>> &grid) {
        int n=grid.size(), m=grid[0].size();
        
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    c++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(q.size()>0){
                        pair<int,int> p=q.front();
                        q.pop();
                        int x=p.first, y=p.second;
                        
                        for(int k=0;k<4;k++){
                            int nx=x+dxy[k][0], ny=y+dxy[k][1];
                            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='1'){
                                grid[nx][ny]='0';
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
        return c;
    }
};
