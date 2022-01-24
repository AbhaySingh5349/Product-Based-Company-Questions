Question Link: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &a) {
        int n=a.size();
        
        sort(a.begin(),a.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(a[0][1]);
        
        int c=1;
        for(int i=1;i<n;i++){
            while(pq.size()>0 && pq.top()<=a[i][0]) pq.pop();
            pq.push(a[i][1]);
            if(pq.size()>c) c=pq.size();
        }
        return c;
    }
};
