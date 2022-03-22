class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return intervals.size();
        }

        map<int, int> meetings;
        for (auto& interval : intervals) {
            meetings[interval.front()]++;
            meetings[interval.back()]--;
        }
        
        int sum = 0, maxSum = 0;
        for (auto& kv : meetings) {
            sum += kv.second;
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};
