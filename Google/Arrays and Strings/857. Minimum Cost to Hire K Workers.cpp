Question Link: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/

// Approach 1:

class Solution {
public:
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> v;
        int n=quality.size();
        for(int i=0;i<n;i++){
            double factor=wage[i]/(double)quality[i];
            v.push_back({factor,quality[i]});
        }
        
        sort(v.begin(),v.end());
        
        double ans=DBL_MAX;
        for(int i=k-1;i<n;i++){
            double factor=v[i].first;
            
            vector<double> offers;
            for(int j=0;j<=i;j++){
                double offer = v[j].second*factor;
                offers.push_back(offer);
            }
            
            priority_queue<double> pq;
            for(int j=0;j<offers.size();j++){
                if(pq.size()<k){
                    pq.push(offers[j]);
                }else if(pq.size()==k){
                    if(pq.top()>offers[j]){
                        pq.pop();
                        pq.push(offers[j]);
                    }
                }
            }
            
            double cost=0.0;
            while(pq.size()>0){
                cost += pq.top();
                pq.pop();
            }
            if(ans > cost) ans=cost;
        }
        return ans;
    }
};

// Approach 2:

class Solution {
public:
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> v;
        int n=quality.size();
        for(int i=0;i<n;i++){
            double factor=wage[i]/(double)quality[i];
            v.push_back({factor,quality[i]});
        }
        
        sort(v.begin(),v.end());
        
        priority_queue<int> pq; // max heap
        
        double ans=DBL_MAX;
        int q=0;
        for(int i=0;i<n;i++){
            if(pq.size()<k){
                pq.push(v[i].second);
                q += v[i].second;
            }else if(pq.size()==k){
                if(pq.top()>v[i].second){
                    q -= pq.top();
                    pq.pop();
                    
                    pq.push(v[i].second);
                    q += v[i].second;
                }
            }
            if(pq.size()==k){
                double cost = q*v[i].first;
                if(ans > cost) ans=cost;
            }
        }
        return ans;
    }
};
