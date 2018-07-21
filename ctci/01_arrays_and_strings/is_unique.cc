#include <bits/stdc++.h>
using namespace std;

/**
 * Runtime: O(n)
 * Space: O(n)
 */
bool has_unique_char(const string& data)
{
	unordered_set<char> existed_chars;
	for (char it : data) {
		if (existed_chars.find(it) != existed_chars.end()) {
			// Character found in existed_chars
			return false;
		} else {
			existed_chars.insert(it);
		}
	}

	return true;
}

bool has_unique_char_2(const string& data)
{
	for (int i = 0; i < data.size(); ++i) {
		for (int j = i + 1; j < data.size(); ++j) {
			if (data[i] == data[j]) {
				return false;
			}
		}
	}

	return true;
}
