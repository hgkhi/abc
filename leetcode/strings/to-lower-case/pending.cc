/**
 * Runtime  O(n)
 * Space    O(1)
 */
class Solution {
public:
    string toLowerCase(string str) {
        int diff = 'A' - 'a';
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] -= diff;
            }
        }
        return str;
    }
};
