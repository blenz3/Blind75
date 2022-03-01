class Solution {
public:
    
#if 0
    // Brute force
    //  - For each value from 1 .. n and the value with the mask 0x1 and add it
    //    to our counter. Right shift once until n has exhausted all bits
    //  - Time is O(n * lgn) where n is the input n and lgn is the max number of bits in n
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            result[i] = countHighBits(i);
        }
        return result;
    }
    
    int countHighBits(int n) {
        int count(0);
        while (n) {
            count += (n & 0x1);
            n >>= 1;
        }
        
        return count;
    }
#endif
    
    // Optimized solution
    //  - Use partial solutions to build up a better solution
    //  - For any given n we know that there are a max of lg n 1's in it
    vector<int> countBits(int n) {
        // Seed the result array with 1's so that all power of 2 lookups are 
        // successful (e.g. they will always be 1). All other values will simply be
        // overriden
        std::vector<int> result(n + 1, 1);
        result[0] = 0;
        
        
        int currentPowerOf2 = 2;
        for (int i = 3; i <= n; ++i) {
            // If we are on a power of 2 then we are already good to go aside from updating the nearest
            if (i == currentPowerOf2 << 1) {
                currentPowerOf2 <<= 1;
                continue;
            }
            
            // Get the bits in the nearest power of 2 and lookup the 
            // remainder in the previous results;
            result[i] = result[currentPowerOf2] + result[i - currentPowerOf2];
            
        }
        
        return result;
    }
};
