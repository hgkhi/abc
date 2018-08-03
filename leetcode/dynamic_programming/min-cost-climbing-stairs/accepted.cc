/**
 * Runtime  O(n)
 * Space    O(n)
 */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> total_cost(cost.size() + 1);
        total_cost[0] = 0;
        total_cost[1] = 0;
        
        for (int i = 2; i < total_cost.size(); ++i) {
            total_cost[i] = min(total_cost[i - 1] + cost[i - 1],
                                total_cost[i - 2] + cost[i - 2]);
        }
        
        return total_cost[cost.size()];
    }
};
