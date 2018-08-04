/**
 * Runtime  O(nm)
 * Space    O(n)
 * Where    n: number of words, m: characters in a word
 */
class Solution {
private:
    const vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.",
        "....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
        "...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> string_set;

        for (string word : words) {
            string encoded = "";
            for (char c : word) {
                encoded += code[c - 'a'];
            }
            string_set.insert(encoded);
        }

        return string_set.size();
    }
};
