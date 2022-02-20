class Solution {
public:
    static const int NOT_FOUND =  -1;
    
#if 0
    // Brute Force Solution
    //  - Iterate through each pair of numbers and check if their sum equals the target
    //  - Runtime O(n^2)
    //  - Space O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        
        return std::vector{ -1, -1 };
    }
#endif
    
#if 0
    // Optimized for runtime not for space
    //  - Create a hashmap of each number to the list of indices that correspond to it
    //  - Iterate through each element in the input numbers and check for the complement of 
    //    the number and the target
    //  - Runtime O(n) as hashmap insertion and search is O(1) and we have to check each input
    //  - Space O(n) as we will maintain a record in the hashmap for each input
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, std::vector<int>> indexMap;
        for (int i = 0; i < nums.size(); ++i) {
            indexMap[nums[i]].push_back(i);
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            auto findIt = indexMap.find(complement);
            if (findIt == indexMap.end()) {
                continue;
            }
            
            // Special case to ensure that if the complement is the same as the input number
            // we don't double count
            if (complement != nums[i]) {
                return { i, findIt->second.front() };   
            }
            
            auto& matchingIndexes = findIt->second;
            if (matchingIndexes.size() > 1) {
                return { i, matchingIndexes.back() }; 
            }
        }
        
        
        return std::vector{ -1, -1 };
    }
#endif 
    
    // One pass hash table
    //  - Create a hashmap of each number to the list of indices that correspond to it
    //  - As we insert into it we can check if the complement exists
    //  - Runtime O(n) as hashmap insertion and search is O(1) and we have to check each input
    //  - Space O(n) as we will maintain a record in the hashmap for each input
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, std::vector<int>> indexMap;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            auto findIt = indexMap.find(complement);
            if (findIt != indexMap.end()) {
                return { i, findIt->second.front() };
            }
            
            indexMap[nums[i]].push_back(i);
        }
      
        
        return std::vector{ -1, -1 };
    }

};
