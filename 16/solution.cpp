class Solution {
public:
    
    // Dyanmic Programming with space
    //  - We know that for n == 1 that there is only one path (a 1 step) and for n == 2 
    //    there are two paths (2 1 steps or 1 2 step). For each additional step we know that 
    //    we can take all of the distinct paths up to that point with a 1 step (i.e. n - 1) 
    //    and all the distinct paths from a 2 step (i.e. n - 2)
    //  - Runtime linear
    //  - Space linear
    int climbStairs(int n) {
        
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        
        std::vector<int> stairs(n + 1, 0);
        stairs[1] = 1;
        stairs[2] = 2;
        
        for (int i = 3; i < stairs.size(); ++i) {
            stairs[i] = stairs[i - 1] + stairs[i - 2];
        }
        
        return stairs[n];
    }
};
