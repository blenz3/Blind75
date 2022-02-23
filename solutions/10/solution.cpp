class Solution {
public:
#if 0
    // Brute Force
    //    - For each pair of heights we capture the area to find the maximum
    int maxArea(vector<int>& height) {
        int maxHeight(0);
        for (int i = 0; i < height.size(); ++i) {
            for  (int j = i + 1; j < height.size(); ++j) {
                int currentHeight = std::min(height[i], height[j]);
                maxHeight = std::max(maxHeight, currentHeight * (j - i));
            }
        }
        
        return maxHeight;
    }
#endif
    // Two pointer approach
    //  - One at head and one at tail. We know that since the area will be decreasing as we
    //    close in from either side so we need to optimize for the higher heights 
    //  - We'll keep track of the max area so far along the way
    int maxArea(vector<int>& height) {
        int largestArea(0);
        int head = 0, tail = height.size() - 1;
        while (head < tail) {
            int currentHeight = std::min(height[head], height[tail]);
            int currentArea = currentHeight * (tail - head);
            largestArea = std::max(largestArea, currentArea);
            if (height[head] > height[tail]) {
                tail--;
            } else {
                head++;
            }
        }
        return largestArea;
    }
};
