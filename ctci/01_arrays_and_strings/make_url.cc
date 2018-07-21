#include <bits/stdc++.h>
using namespace std;

/**
 * Runtime: O(n)
 * Space: O(1)
 */
void make_url(char* data, size_t virtual_size, size_t buffer_size)
{
	char* p1 = data + virtual_size - 1;
	char* p2 = data + buffer_size - 1;
	*(p2--) = '\0';
	while (p1 < p2) {
		if (*p1 == ' ') {
			*(p2--) = '0';
			*(p2--) = '2';
			*(p2--) = '%';
		} else {
			*(p2--) = *p1;
		}
		--p1;
	}
}
