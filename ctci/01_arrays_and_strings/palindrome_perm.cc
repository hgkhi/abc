#include <bits/stdc++.h>
using namespace std;

/**
 * Assume that the data is [az]
 * For some details like: space, special characters, we can modify the code
 * later with ease.
 *
 * Runtime: O(n)
 * Space: O(n)
 */
bool is_pal_perm(const string& data)
{
	unordered_map<char, size_t> char_counter;

	for (char it : data) {
		++char_counter[it];
	}

	bool odd_flag = false;
	for (auto it : char_counter) {
		if (it.second % 2 == 1) {
			if (odd_flag) {
				return false;
			} else {
				odd_flag = true;
			}
		}
	}

	return true;
}
