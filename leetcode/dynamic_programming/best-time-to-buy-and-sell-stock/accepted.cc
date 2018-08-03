/**
 * Runtime  O(n)
 * Space    O(1)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy_at = 0;
        
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[buy_at]) {
                max_profit = max(max_profit, prices[i] - prices[buy_at]);
            } else {
                buy_at = i;
            }
        }
        
        return max_profit;
    }
};
