#include <bits/stdc++.h>
using namespace std;

/**
 * Runtime: O(n)
 * Space: O(n)
 *	The result to be return is also counted
 */
string compress_str(const string& data)
{
	size_t p1 = 0;
	string shortened = "";
	while (p1 < data.size()) {
		size_t p2 = p1 + 1;
		while (p2 < data.size() && data[p1] == data[p2]) {
			++p2;
		}
		shortened += (data[p1] + to_string(p2 - p1));
		p1 = p2;
	}

	return shortened.size() < data.size() ? shortened : data;
}
