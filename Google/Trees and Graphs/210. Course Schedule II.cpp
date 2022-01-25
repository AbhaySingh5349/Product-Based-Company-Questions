Question Link: https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> graph[n], indegree(n,0);
        
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0], v=pre[i][1];
            graph[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int c=0;
        vector<int> ans(n);
        while(q.size()>0){
            int src=q.front();
            q.pop();
            ans[c]=src;
            c++;
            
            for(int i=0;i<graph[src].size();i++){
                int child=graph[src][i];
                indegree[child]--;
                if(indegree[child]==0) q.push(child);
            }
        }
        if(c<n) return {};
        return ans; 
    }
};
