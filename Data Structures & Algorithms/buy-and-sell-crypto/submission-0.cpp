class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        int maxprofit = 0;
        int min = prices[0];
        int n = prices.size();

        for(int i = 0; i<n; i++){
            int profit = prices[i] - min;

            if (profit > maxprofit){
                maxprofit = profit;
            }
            if(min > prices[i]){
                min = prices[i];
                
            }
        }
        return maxprofit;
    }
};