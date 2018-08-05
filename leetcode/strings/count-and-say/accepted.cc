#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n)
    {
        string result = "1";
        string previous = result;
        
        for (int i = 1; i < n; ++i) {
            int p_slow = 0;
            result = "";
            while (p_slow < previous.size()) {
                int p_fast = p_slow + 1;
                while (p_fast < previous.size() && previous[p_slow] == previous[p_fast]) {
                    p_fast += 1;
                }
                
                result += to_string(p_fast - p_slow);
                result += previous[p_slow];
                p_slow = p_fast;
            }
            previous = result;
        }
        
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.countAndSay(5) << endl;
}
