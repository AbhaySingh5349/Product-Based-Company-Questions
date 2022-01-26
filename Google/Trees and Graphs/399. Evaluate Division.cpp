Question Link: https://leetcode.com/problems/evaluate-division/

class Solution {
public:
    
    void solve(map<string,vector<pair<string,double>>> &graph, string src, string dst, double &val, double temp, set<string> &visited){
        if(src==dst){
            val=temp;
            return;
        }
        visited.insert(src);
        
        vector<pair<string,double>> cur=graph[src];
        for(int i=0;i<cur.size();i++){
            string child=cur[i].first;
            double w=cur[i].second;
            if(visited.find(child)==visited.end()){
                solve(graph,child,dst,val,temp*w,visited);
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>> graph;
        set<string> nodes;
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0], v=equations[i][1];
            double w=values[i];
            graph[u].push_back({v,w});
            graph[v].push_back({u,1.0/w});
            nodes.insert(u);
            nodes.insert(v);
        }
        
        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            string u=queries[i][0], v=queries[i][1];
            double temp=1.0, val=-1.0;
            set<string> visited;
            if(nodes.find(u)!=nodes.end() && nodes.find(v)!=nodes.end()) solve(graph,u,v,val,temp,visited);
            ans.push_back(val);
        }
        return ans;
    }
};
