using Interval = vector<int>;
using Intervals = vector<Interval>;

class Solution {
public:
    // Step 1: search - bs
    // Step 2: How to insert
    //      - Case 1: Entirely inside an existing interval == no change
    //      - Case 2: Entirely outside an existing interval == prepend new interval
    //      - Case 3: Start of new interval inside existing interval but end is outside
    // Step 3: Accumulate subsumed intervals
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // In the case where no intervals exist just return the interval
        if (intervals.empty()) {
            return Intervals{newInterval};
        }
        
        SearchResult start = binarySearch(intervals, newInterval.front());
        SearchResult end = binarySearch(intervals, newInterval.back());
        
        // In the case that the start and end are entirely in the existing interval then just return
        // since nothing has changed
        if (start.index == end.index && start.inExisting && end.inExisting) {
            return intervals;
        }
        
        // Now that we know that one or more intervals has to be changed let's do that.
        // Firstly we know that all intervals before the start interval can be copied to our
        // result vector
        Intervals result;
        result.reserve(intervals.size());
        for (int i = 0; i < start.index; ++i) {
            result.push_back(intervals[i]);
        }
        
        // Now we're at the start of our merged intervals - we shall begin by finding the 
        // start value of the new interval. In the case that the inserted interval is outside
        // of the interval we've identified then we know that we need a new start value (the
        // one given by the input). Otherwise we just reuse the existing interval's value
        Interval insertedInterval;
        if (!start.inExisting) {
            insertedInterval.push_back(newInterval.front());
        } else {
            insertedInterval.push_back(intervals[start.index].front());
        }
        
        // Now do the same for the end interval. If the end doesn't exist in anything then just use the 
        // value from the new interval
        if (!end.inExisting) {
            insertedInterval.push_back(newInterval.back());
        } else {
            insertedInterval.push_back(intervals[end.index].back());
        }
        
        // Now that we've created our new interval we have the sad task of figuring out which other 
        // intervals to add back in. We know at this point that every interval after the end index
        // definitely goes back in but there are tricky cases of prepending a completely new interval
        // and postpending an entirely new interval
        result.push_back(insertedInterval);
        
        // Check if we need to see if the previous intervals[end.index] has been
        // totally consumed and bypass it if not
        int insertIndex = end.index;
        if (insertIndex < intervals.size() && insertedInterval.back() == intervals[end.index].back())
            insertIndex++;
    
        for (int i = insertIndex; i < intervals.size(); ++i) {
            result.push_back(intervals[i]);
        }
        
        return result;
    }
    
private:
    
    struct SearchResult {
        int index;
        bool inExisting;
        
        SearchResult(int idx, bool exists) : index(idx), inExisting(exists) {}
    };
    
    SearchResult binarySearch(const Intervals& intervals, int val) {
        int left = 0, right = intervals.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (val >= intervals[mid].front() && val <= intervals[mid].back()) {
                return SearchResult(mid, true);
            } else if (val > intervals[mid].back()) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return SearchResult(left, false);
    }
};
