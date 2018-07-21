#include <bits/stdc++.h>
using namespace std;
;
/**
 * data_1 and data_2 are expected to have the same length
 */
size_t order_diff(const string& data_1, const string& data_2)
{
	size_t result = 0;

	for (size_t i = 0; i < data_1.size(); ++i) {
		if (data_1[i] != data_2[i]) {
			++result;
		}
	}

	return result;
}

bool has_one_char_missing(const string& small_str, const string& big_str)
{
	size_t skip_flag = 0;
	for (size_t i = 0; i < small_str.size(); ++i) {
		if (small_str[i] != big_str[i + skip_flag]) {
			++skip_flag;
			if (skip_flag > 1) {
				return false;
			}
		}
	}

	return true;
}

size_t size_t_abs(size_t val_1, size_t val_2)
{
	if (val_1 > val_2) {
		return val_1 - val_2;
	} else {
		return val_2 - val_1;
	}
}

/**
 * Runtime: O(n)
 * Space: O(1)
 */
bool is_one_distance(const string data_1, const string& data_2)
{
	if (size_t_abs(data_1.size(), data_2.size()) > 1) {
		// If the size diff is larger than 1
		// No way the edit distance is 1 or 0
		return false;
	} else if (data_1.size() == data_2.size()) {
		// In case the size is the same
		// The order-diff must not exceed 2
		return order_diff(data_1, data_2) < 2;
	} else if (data_1.size() > data_2.size()) {
		// In case data_1 has one more character than data_2
		return has_one_char_missing(data_2, data_1);
	} else {
		// data_2 has one more character than data_1
		return has_one_char_missing(data_1, data_2);
	}
}
