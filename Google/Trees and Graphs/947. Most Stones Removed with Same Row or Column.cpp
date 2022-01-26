Question Link: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    
    int find(int u, vector<int> &parent){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u],parent);
    }
    
    void merge(int pu, int pv, vector<int> &parent, vector<int> &rk){
        if(rk[pu]>=rk[pv]){
            rk[pu]+=rk[pv];
            parent[pv]=pu;
        }else{
            rk[pv]+=rk[pu];
            parent[pu]=pv;
        }
    }
    
    int removeStones(vector<vector<int>> &a) {
        int n=1, m=1;
        for(int i=0;i<a.size();i++){
            n=max(n,a[i][0]+1);
            m=max(m,a[i][1]+1);
        }
        
        vector<int> parent(n+m), rk(n+m);
        for(int i=0;i<n+m;i++){
            parent[i]=i;
            rk[i]=1;
        }
        
        for(int i=0;i<a.size();i++){
            int pu=find(a[i][0],parent), pv=find(a[i][1]+n,parent);
            if(pu!=pv) merge(pu,pv,parent,rk);
        }
        
        map<int,int> mp;
        for(int i=0;i<a.size();i++){
            int root=find(a[i][0],parent);
            mp[root]++;
        }
        
        int ans=0;
        
        map<int,int> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            ans += (it->second-1);
        }
        
        return ans;
    }
};
