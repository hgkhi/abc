#include <bits/stdc++.h>
using namespace std;

/**
 * Runtime: O(n + N)
 *	n: size of string
 *	N: number of bucket in hashtable
 * Space: O(n)
 * 
 */
bool is_perm(const string& data_1, const string& data_2)
{
	if (data_1.size() != data_2.size()) {
		return false;
	}

	unordered_map<char, size_t> freq_map;
	for (char it : data_1) {
		++freq_map[it];
	}

	for (char it : data_2) {
		--freq_map[it];
	}

	for (auto it : freq_map) {
		if (it.second != 0) {
			return false;
		}
	}

	return true;
}
