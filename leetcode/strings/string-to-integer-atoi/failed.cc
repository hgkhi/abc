/**
 * Failed at: "9223372036854775808"
 */
class Solution {
    private:
        inline bool is_digit(const char& c)
        {
            return c >= '0' && c <= '9';
        }
    public:
        int myAtoi(string str)
        {
            long scalar = 0;
            bool positive = true;
            
            int ptr = 0;
            while (ptr < str.size() && str[ptr] == ' ') {
                ++ptr;
            }

            if (ptr >= str.size()) {
                return 0;
            }

            if (str[ptr] == '+') {
                ptr += 1;
            } else if (str[ptr] == '-') {
                positive = false;
                ptr += 1;
            } else if (is_digit(str[ptr])) {
                // cool
            } else {
                return 0;
            }

            while (ptr < str.size() && is_digit(str[ptr])) {
                scalar = scalar * 10 + (str[ptr] - '0');
                ptr += 1;
            }

            if (positive) {
                if (scalar > INT_MAX) {
                    return INT_MAX;
                }

                return scalar;
            } else {
                if (0 - scalar < INT_MIN) {
                    return INT_MIN;
                }
                
                return 0 - scalar;
            }
        }
};
