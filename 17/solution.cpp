class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> change(amount + 1, INT_MAX);
        change[0] = 0;
        for (auto coin : coins) {
            for (int i = 1; i * coin < amount; ++i) {
                change[i * coin] = std::min(i, change[i * coin]);
            }   
        }
        
        // For each index we take the min of the current value and each 
        // subsequent value in the array that could have a coin added to it
        // and result in the current index (e.g. for index 5 and coins [1,2,3] we 
        // would take the min of amounts[i], amounts[i - 1] + 1, amounts[i - 2] + 1, etc)
        for (int i = 1; i <= amount; ++i) {
            int currentMin = change[i];
            for (auto coin : coins) {
                if (i - coin >= 0 && change[i - coin] != INT_MAX) {
                    currentMin = std::min(currentMin, change[i - coin] + 1);
                }
            }
            change[i] = currentMin;
        }
        return (change[amount] != INT_MAX) ? change[amount] : -1;
    }
    
    
    void printVector(const vector<int>& coins) {
        printf("[");
        for (auto coin : coins) {
            printf(" %d,", coin);
        }
        printf("]\n");
    }
};
