#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int count5 = 0;
        int count10 = 0;
        
        for (int bill : bills) {
            if (bill == 5) {
                count5 += 1;
            } else if (bill == 10) {
                count10 += 1;
                count5 -= 1;
                if (count5 < 0) {
                    return false;
                }
            } else {
                count10 -= 1;
                count5 -= 1;
                if (count10 < 0 || count5 < 0) {
                    count10 += 1;
                    count5 -= 2;
                    if (count5 < 0) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};

int main()
{
    vector<int> data = {5, 5, 10, 20};
    Solution sol;
    cout << sol.lemonadeChange(data) << endl;
}
