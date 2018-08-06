#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {       
        int p_buy = 0;
        int profit = 0;

        while (p_buy < prices.size()) {
            int p_sell = p_buy + 1;
            while (p_sell < prices.size() && prices[p_sell] >= prices[p_sell - 1]) {
                ++p_sell;
            }
            profit += (prices[p_sell - 1] - prices[p_buy]);
            p_buy = p_sell;
        }

        return profit;
    }
};

int main()
{
    Solution sol;
    vector<int> data = {7,6,4,3,1};
    cout << sol.maxProfit(data) << endl;
}
