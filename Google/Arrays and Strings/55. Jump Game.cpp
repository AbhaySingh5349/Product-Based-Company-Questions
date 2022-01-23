Question Link: https://leetcode.com/problems/jump-game/

// Approach 1:

class Solution {
public:
    bool canJump(vector<int>& a) {
        int n=a.size();
        
        vector<bool> dp(n,false);
        dp[n-1]=true;
        
        for(int i=n-2;i>=0;i--){
            int steps=a[i];
            for(int j=i+1;j<=min(n-1,i+steps);j++){
                if(dp[j]==true){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};

// Approach 2:

class Solution {
public:
    bool canJump(vector<int> &a) {
        int n=a.size();
        if(n==1) return true;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; 
        
        pq.push({a[0],0});
        for(int i=1;i<n;i++){
            while(pq.size()>0 && pq.top().first<i) pq.pop();
            
            if(pq.size()==0) return false;
            if(pq.top().first>=n-1) return true;
            pq.push({i+a[i],i});
        }
        return false;
    }
};

// Approach 3:

class Solution {
public:
    bool canJump(vector<int> &a) {
        int n=a.size();
        
        int pos=a[0];
        for(int i=1;i<n;i++){
            if(pos<i) return false;
            pos=max(pos,i+a[i]);
        }
        return true;
    }
};
