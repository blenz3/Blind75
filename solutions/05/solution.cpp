class Solution {
public:
#if 0
    // Brute force
    //  - Iterate each possible combination of start, end indices and sum the subarray
    //  - time O(n^3)
    //  - space constant
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)
            return nums.front();
        
        int64_t max_num =  INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                int64_t sum  = 0;
                for (int k = i; k <= j; ++k)
                    sum += nums[k];
                
                max_num = std::max(max_num,  sum);
            }
        }
        
        return max_num;
    }
#endif
    
    
    // Optimized 
    //  - Greedy single pass which tracks the current subarray. 
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0];
        int runningTotal = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            runningTotal = std::max(nums[i], runningTotal + nums[i]);
            maxSoFar = std::max(maxSoFar, runningTotal);
        }
        
        return maxSoFar;
    }
};
