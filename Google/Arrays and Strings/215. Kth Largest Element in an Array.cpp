Question Link: https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int> &a, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<a.size();i++){
            if(pq.size()<k){
                pq.push(a[i]);
            }else if(pq.size()==k){
                if(pq.top()<a[i]){
                    pq.pop();
                    pq.push(a[i]);
                }
            }
        }
        return pq.top();
    }
};
