class Solution {
public:
    static const int NOT_FOUND = -1;
    
#if 0
    // Brute force
    //      - Linearly search for the target
    //      - Space constant
    //      - Time linear
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                return i;
            }
        }
        
        return NOT_FOUND;
    }
#endif
    
    // Optimized 
    //      - Find the pivot point by binary searching for it and then binary search each side
    //      - Time lgn
    //      - Space constant
    int search(const vector<int>& nums, const int target) {
        if (nums.empty()) {
            return NOT_FOUND;
        }
        
        // Find the pivot point and then search each side 
        int pivot = findPivot(nums);
        
        // Search each side
        int result;
        if ((result = binarySeachRange(nums, target, 0, pivot - 1)) != NOT_FOUND) {
            return result;
        } 
        
        return binarySeachRange(nums, target, pivot, nums.size() - 1);
        
    }
    
private:
    
    int findPivot(const vector<int>& nums) {
        int start = 0, end = nums.size() - 1, minVal = INT_MAX, minIdx = 0;
        while (start < end) {
            int midpoint = (start + end) / 2;
            trackMinimums(nums, midpoint, minVal, minIdx);
            
            if (nums[midpoint] >  nums[end]) { // search right
                start = midpoint + 1;
                trackMinimums(nums, end, minVal, minIdx);
            } else {
                end = midpoint - 1;
                trackMinimums(nums, start, minVal, minIdx);
            }
        }

        return minIdx;
    }
    
    void trackMinimums(const vector<int>& nums, int index, int& minValue, int& minIndex) {
        if (nums[index] < minValue) {
            minValue = nums[index];
            minIndex = index;
        }
    }
    
    int binarySeachRange(const vector<int>& nums, const int target, int start, int end) {
            while (start <= end) {
                int midpoint = (start + end) / 2;
                if (nums[midpoint] == target) {
                    return midpoint;
                } else if (nums[midpoint] < target) { //search right
                    start = midpoint + 1;
                } else {
                    end = midpoint - 1;
                }
            }
            
            return NOT_FOUND;
    }
    
};
