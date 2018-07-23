#include <bits/stdc++.h>
using namespace std;

/**
 * Runtime: O(n*m)
 * Space: O(1)
 */
bool is_substring(const string& str_1, const string& str_2)
{
	return str_2.find(str_1) != string::npos;	// no position
}

/**
 * Runtime: O(n) + O(n*2n) = O(n^2)
 * Space: O(n)
 */
bool is_rotation(const string& str_1, const string& str_2)
{
	if (str_1.size() != str_2.size()) {
		return false;
	}

	string haystack = str_1 + str_1;
	return is_substring(str_2, haystack);
}

int main()
{
	cout << is_rotation("cunty", "tycun") << endl;
}
