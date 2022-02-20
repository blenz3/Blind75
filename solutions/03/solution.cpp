class Solution {
public:
#if 0
    // Brute force 
    //  - Check each pair to see if any show up twice
    //  - Time quadratic
    //  - Space constant
    bool containsDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        
        return false;
    }
#endif
    
#if 0
    // Optimized for time
    //  - Insert elements to hash set check if sizes are equal
    //  - Time linear
    //  - Space linear
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> numbers_encountered(nums.begin(), nums.end());
        return (numbers_encountered.size() != nums.size());
    }
#endif

#if 0
    // Optimized for time + 1
    //  - Insert elements to hash set check if sizes are equal
    //  - Time linear
    //  - Space linear
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> numbers_encountered;
        for (int num : nums) {
            auto find_it = numbers_encountered.find(num);
            if (find_it != numbers_encountered.end())
                return true;
            
            numbers_encountered.insert(num);
        }
        
        return false;
    }
#endif
    
    // Optimized for space
    //  - Sort in place then walk the list comparing pair wise
    //  - Time nlgn
    //  - Space const
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) 
                return true;
        }
        return false;
    }
};
