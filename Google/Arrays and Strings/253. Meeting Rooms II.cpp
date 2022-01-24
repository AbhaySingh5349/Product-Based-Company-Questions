Question Link: https://leetcode.com/problems/meeting-rooms-ii/

// Approach 1:

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

// Approach 2:

class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &a) {
        int maxe=0;
        for(int i=0;i<a.size();i++) maxe=max(maxe,a[i][1]);
        
        vector<int> scanline(maxe+1,0);
        for(int i=0.;i<a.size();i++){
            int s=a[i][0], e=a[i][1];
            scanline[s]++, scanline[e]--;
        }
        
        int ans=1;
        for(int i=1;i<maxe+1;i++){
            scanline[i] += scanline[i-1];
            ans=max(ans,scanline[i]);
        }
        return ans;
    }
};
