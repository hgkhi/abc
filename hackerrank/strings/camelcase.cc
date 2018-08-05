/**
 * https://www.hackerrank.com/challenges/camelcase/problem
 * Runtime  O(n)
 * Space    O(1)
 */
int camelcase(string s) {
    int count = 1;
    for (char c : s) {
        if (c >= 'A' && c <= 'Z')
            count += 1;
    }
    
    return count;
}
