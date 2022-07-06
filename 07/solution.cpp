class Solution {
public:
#if 0
    // Brute Force
    //  - Linear search for the minimum value and return it
    //    the array has been rotated
    //  - Time linear
    //  - Space constant
    int findMin(vector<int>& nums) {
        int min = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            min = std::min(min, nums[i]);
        }
        return min;
    }
#endif
    
    // Optimized 
    //  - Binary search 
    //  - Time lgn
    //  - Space const
    int findMin(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1, min = INT_MAX;
        while (begin <= end) {
            
            int mid = (begin + end) / 2;
            min = std::min(nums[mid], min);
            // If the midpoint is less than the earlier bound we need to keep searching left
            if (nums[mid] < nums[begin]) {
                min = std::min(nums[end], min);
                end = mid - 1;
            } else {
                min = std::min(nums[begin], min);
                begin = mid + 1;
            }
        }
        
        return min;
    }
};
