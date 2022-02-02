Question Link: https://leetcode.com/problems/my-calendar-ii/

// Approach 1:

class MyCalendarTwo {
public:
    
    map<int,int> mp;
    
    MyCalendarTwo() {
        mp.clear();
    }
    
    bool book(int start, int end) {
        mp[start]++, mp[end]--;
        
        int count=0;
        for(auto it : mp){
            count += (it.second);
            if(count>2){
                mp[start]--, mp[end]++;
                return false;
            }
        }
        return true;
    }
};

// Approach 2:

class MyCalendarTwo {
public:
    
    vector<pair<int,int>> events, doubleEvents;
    
    MyCalendarTwo() {
        events.clear();
        doubleEvents.clear();
    }
    
    bool book(int start, int end) {
        for(pair<int,int> &p : doubleEvents){
            // tripple overlap
            if(start<p.second && end>p.first) return false;
        }
        
        for(pair<int,int> &p : events){
            // double overlap
            if(start<p.second && end>p.first){
                doubleEvents.push_back({max(start,p.first),min(end,p.second)});
            }
        }
        events.push_back({start,end});
        return true;
    }
};
