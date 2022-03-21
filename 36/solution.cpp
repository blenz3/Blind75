class Solution {
public:
    // Insert all start indexes and end indexes into an ordered map with a 
    // + 1 or - 1 accumulator modifier for each range begin and end respectively.
    // (O(nlgn) time due to sort, O(n) space due to copy)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::map<int, int> intervalPoints;
        for (auto& interval : intervals) {
            intervalPoints[interval.front()]++;
            intervalPoints[interval.back()]--;
        }
        
        intervals.clear();
        int intervalCounter = 0, start = -1;
        for (auto& kvp : intervalPoints) {
            intervalCounter += kvp.second;
            // Handle slices (e.g. intervals like [0, 0])
            if (intervalCounter == 0 && start == -1 && kvp.second == 0) {
                intervals.push_back(vector<int>{kvp.first, kvp.first});
            }
            // Handle start of a new interval
            else if (start == -1) {
                start = kvp.first;
            }
            // Handle end of an interval
            else if (intervalCounter == 0) {
                intervals.push_back(vector<int>{start, kvp.first});
                start = -1;
            }
            
        }
        
        return intervals;
    }
};
