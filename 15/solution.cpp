class Solution {
public:
    // Straight up swap
    uint32_t reverseBits(uint32_t n) {
        int out = 0;
        for (int i = 0; i < 32; ++i) {
            out <<= 1;
            int tmp = n & 1;
            out += tmp;
            n >>= 1;
        }
        
        return out;
    }
};
