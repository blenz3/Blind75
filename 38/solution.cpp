class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) 
            return true;
        
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i][1] > intervals[i + 1][0])
                return false;
        }
        
        return true;
    
    }
#if 0    
    // Better solution
        //  - Plot them in a map and then create a counter for each start 
        //    and decrease for each end
        //  - if sum ever exceeds 1 then it is bad!
    bool mapMeetings(const vector<vector<int>>& intervals) { 
        map<int, int> meetings;
        for (auto& interval : intervals) {
            meetings[interval.front()]++;
            meetings[interval.back()]--;
        }
        
        int sum = 0;
        for (auto& kv : meetings) {
            sum += kv.second;
            if (sum > 1) 
                return false;
        }
        
        return true;
    }
    
    // Brute force
    //   - check each interval against each other interval
    //.  - if the meetings overlap at all then cannot attend
    bool bruteForceMeetings(const vector<vector<int>>& intervals) {
        for (int i = 0; i < intervals.size(); ++i) {
            for (int j = i + 1; j < intervals.size(); ++j) {
                bool result = false;
                result |= (intervals[i].front() >= intervals[j].front() && intervals[i].front() < intervals[j].back());
                result |= (intervals[i].back() > intervals[j].front() && intervals[i].back() <= intervals[j].back());
                result |= (intervals[j].back() > intervals[i].front() && intervals[j].back() <= intervals[i].back());
                result |= (intervals[j].front() >= intervals[i].front() && intervals[j].front() < intervals[i].back());
                if (result)
                    return false;
            }
        }
        
        return true;
    }
#endif
};
