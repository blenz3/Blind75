class Solution {
public:
    
#if 0
    // Brute Force 
    //  - For each element get the product of the array except for itself
    //  - Time is quadratic
    //  - Space is constant (linear I guess because we are returning an arrray?)
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out;
        for (int i = 0; i < nums.size(); ++i) {
            int product(1);
            for (int j = 0; j < nums.size(); ++j) {
                if (j == i) 
                    continue;
                
                product *= nums[j];
            }
            
            out.push_back(product);
        }
        
        return out;
    }
#endif 
    
    // Optimized
    //  - Get the product of the entire set of numbers except for zeroes. Set a flag that a zero was encountered somewhere
    //  - For each element divide the clean product w/ the element unless it is zero
    //  - Time is linear
    //  - Space is constant 
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int zero_count(0);
        int product(1);
        for (auto num : nums) {
            if (num == 0) {
                zero_count++;
            } else {
                product *= num;
            }
        }
             
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int result;
            if (zero_count > 1) {
                result = 0;
            } else if (num == 0) {
                result = product;
            } else if (zero_count == 1) {
                result = 0;
            } else {
                result = product / num;
            }
            
            nums[i] = result;
        }
        
        return nums;
    }
    
};
