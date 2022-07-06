class Solution {
public:
#if 0
    // Brute Force
    //   - Iterate through each possible subarray and get the product
    //   - Space constant
    //   - Time O(n^3)
    int maxProduct(vector<int>& nums) {
        int max(INT_MIN);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                int product(1);
                for (int k = i; k <= j; ++k) {
                    product *= nums[k];
                }
                
                max = std::max(max, product);
            }
        }
        return max;
    }
#endif
    
    // Revisit
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        // Track the minimum value in the value chain and the maximum so far in the value chain since 
        // the minimum with a negative number can be flipped to positive
        int minSoFar(nums[0]);
        int maxSoFar(nums[0]);
        int result = maxSoFar;
        for (int i = 1; i < nums.size(); ++i) {
            int currentMax = max(nums[i], max(nums[i] * minSoFar, nums[i] * maxSoFar));
            minSoFar = min(nums[i], min(nums[i] * minSoFar, nums[i] * maxSoFar));
            maxSoFar = currentMax;
            
            result = max(maxSoFar, result);
            
        }
        
        return result;
    }
};
