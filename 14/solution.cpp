class Solution {
public:
#if 0
    // Sum all the numbers and compare it to sum of 1..n where n is length of nums
    int missingNumber(vector<int>& nums) {
        int inputSum(0);
        for (auto n : nums) {
            inputSum += n;
        }
        
        int expectedSum = (nums.size() * (nums.size() + 1)) / 2;
        return expectedSum - inputSum;
    }
#endif
    
    // The xor of all the numbers in the range will eventually yield the missing number
    int missingNumber(vector<int>& nums) {
        int accumulator(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            accumulator ^= i ^ nums[i];
        }
        
        return accumulator;
    }
};
