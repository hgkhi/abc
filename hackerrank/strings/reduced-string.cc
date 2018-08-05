/**
 * https://www.hackerrank.com/challenges/reduced-string/problem
 * Runtime  O(n)
 * Space    O(n)
 */
string superReducedString(string s) {
    bool max_compressed = false;
    while (!max_compressed) {
        max_compressed = true;
        string compressed = "";
        int p_slow = 0;
        while (p_slow < s.size()) {
            int p_fast = p_slow + 1;
            while (p_fast < s.size() && s[p_fast] == s[p_slow]) {
                ++p_fast;
                max_compressed = false;
            }
            if ((p_fast - p_slow) % 2 == 1) {
                compressed += s[p_slow];
            }
            p_slow = p_fast;
        }
        s = compressed;
    }
    return s.empty() ? "Empty String" : s;
}
