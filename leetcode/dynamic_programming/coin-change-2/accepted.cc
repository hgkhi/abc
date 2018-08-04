/**
 * Runtime  O(n*m)
 * Space    O(m)
 * Where    m: amount, n: number of currency
 */
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> result(amount + 1, 0);
        result[0] = 1;
        for (int currency : coins) {
            for (int i = currency; i <= amount; ++i) {
                result[i] += result[i - currency];
            }
        }
        
        return result[amount];
    }
};
