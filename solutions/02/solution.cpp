class Solution {
public:
#if 0
    // Brute force
    //  - Iterate each pair of stock prices and find the pair that results in the highest amount of profit
    //  - Time complexity is quadratic 
    //  - Space complexity is constant
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = i + 1; j < prices.size(); ++j) {
                max_profit = std::max(prices[j] - prices[i], max_profit);
            }
        }
        
        return max_profit;
    }
#endif 
    
    // Optimized
    //  - Iterate through the list backwards keeping track of the maximum price and comparing it to 
    //    each price to track the best profit potential
    //  - Time complexity is linear 
    //  - Space complexity is constant
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int max_price = prices.back();
        for (auto rit = prices.rbegin(); rit != prices.rend(); ++rit) {
            max_price = std::max(max_price, *rit);
            max_profit = std::max(max_profit, max_price - *rit);
        }
        return max_profit;
    }
};
