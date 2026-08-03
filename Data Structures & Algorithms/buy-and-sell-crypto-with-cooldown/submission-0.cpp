class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        // buy[i] = max profit if holding stock at day i
        // sell[i] = max profit if not holding stock at day i
        vector<int> buy(n), sell(n);
        
        buy[0] = -prices[0];  // Buy on day 0
        sell[0] = 0;           // Don't buy on day 0
        buy[1] = max(-prices[0], -prices[1]);  // Buy on day 0 or 1
        sell[1] = max(0, prices[1] - prices[0]);  // Sell on day 1 or don't trade
        
        for (int i = 2; i < n; i++) {
            // Either we bought before, or buy today
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
            
            // Either we held from before, or sell today, or do nothing
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        
        return sell[n - 1];
    }
};