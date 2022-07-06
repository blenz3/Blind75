class Solution {
public:
    
    // Optimized strategty
    //  - Sort the list so we can easily exclude duplicates 
    vector<vector<int>>  threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        if (nums.size() < 3) {
            return out;
        }
        
        std::sort(nums.begin(), nums.end());
        for (int i = 0 ; i < nums.size() - 2; ++i) {
            // For each value we now can just try to find two different elements which we can use to sum
            // to the complement of the current value
            if (i != 0 && nums[i] == nums[i - 1]) 
                continue; 
            
            int head = i + 1;
            int tail = nums.size() - 1;
            while (head < tail) {
                // We found our target
                int sum = nums[head] + nums[tail] + nums[i];
                if (sum == 0) {
                    // Capture this successful triplet
                    out.push_back({nums[i], nums[head], nums[tail]});            
                    
                    // Move the head pointer to the first new value
                    while (head < tail && nums[head] == nums[head + 1]) 
                        head++;
                    
                    // Move the tail pointer to the first new value
                    while (head < tail && nums[tail] == nums[tail - 1])
                        tail--;
                    
                    head++;
                    tail--;
                        
                } else if (sum > 0) {
                    tail--;
                } else {
                    head++;
                }
            }
        }
        return out; // dedupeTriplets(out);
    }
    
#if 0
    // Brute force
    //  - For each triplet i,j,k we check to see if they sum to 0
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    if (i == j || i == k) 
                        continue;
                    
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        triplets.push_back(createTriplet(nums[i], nums[j], nums[k]));
                    }
                }
            }
        }
        
        return dedupeTriplets(triplets);
    }
private:
    vector<int> createTriplet(int a, int b, int c) {
        vector<int> triplet = { a, b, c };
        std::sort(triplet.begin(), triplet.end());
        return triplet;
    }
#endif
    
    vector<vector<int>> dedupeTriplets(const vector<vector<int>>& triplets) {
        vector<vector<int>> out;
        for (auto inputTriplet : triplets) {
            bool addTriplet = true;
            for (auto outputTriplet : out) {
                if (inputTriplet[0] == outputTriplet[0] &&
                    inputTriplet[1] == outputTriplet[1] &&
                    inputTriplet[2] == outputTriplet[2]) {
                    addTriplet = false;
                }
            }
            
            if (addTriplet)
                out.push_back(inputTriplet);
        }
        
        return out;
    }
};
