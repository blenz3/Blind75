class Solution {
public:
#if 0
    // Brute force
    //   - pop bits off from the right 
    int hammingWeight(uint32_t n) {
        int count(0);
        while (n > 0){ 
            count += (n & 1);
            n >>= 1;
        }
        
        return count;
    }
#endif
    
    // Fancier Solution
    //  - Always remove the LSB and add to the count
    int hammingWeight(uint32_t n) {
        int count(0);
        while (n > 0){ 
            count++;
            n &= (n-1);
        }
        
        return count;
    }
    
};
