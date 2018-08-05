#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        inline bool is_digit(const char& c)
        {
            return c >= '0' && c <= '9';
        }
    public:
        int myAtoi(string str)
        {
            bool positive = true;

            // truncate whitespaces
            int ptr = 0;
            while (ptr < str.size() && str[ptr] == ' ') {
                ++ptr;
            }

            if (ptr >= str.size()) {
                return 0;
            }

            if (str[ptr] == '+') {
                ++ptr;
            } else if (str[ptr] == '-') {
                positive = false;
                ++ptr;
            } else if (!is_digit(str[ptr])) {
                return 0;
            }

            // str[ptr] must be a digit at this point!
            int result = 0;
            int previous = result;      // for checking overflow and shit
            bool shit_happens = false;

            while (ptr < str.size() && is_digit(str[ptr])) {
                result = result * 10 + (str[ptr] - '0');
                if (result / 10 != previous) {
                   shit_happens = true;
                   break;
                }
                previous = result;
                ++ptr;
            }

            if (shit_happens) {
                return positive ? INT_MAX : INT_MIN;
            } else {
                return positive ? result : 0 - result;
            }

            return result;
        }
};

int main()
{
    Solution sol;
    cout << sol.myAtoi("12345") << endl;
}
