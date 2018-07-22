#include <bits/stdc++.h>
using namespace std;

/**
 * Runtime: O(n)
 * Space O(1)
 */
void rotate_90_clockwise(vector<vector<int>>& matrix)
{
	size_t size = matrix.size();
	// For each layer
	for (size_t i = 0; i < size / 2; ++i) {
		// For each element on that layer
		for (size_t j = i; j < size - 1 - i; ++j) {
			swap(matrix[i][j], matrix[j][size - 1 - i]);
			swap(matrix[i][j], matrix[size - 1 - i][size - 1 - j]);
			swap(matrix[i][j], matrix[size - 1 - j][i]);
		}
	}
}

void matrix_dump(vector<vector<int>> matrix)
{
	size_t size = matrix.size();
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	size_t size = 5;
	vector<vector<int>> data(size, vector<int>(size));
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j) {
			data[i][j] = i * size + j;
		}
	}
	matrix_dump(data);
	rotate_90_clockwise(data);
	cout << endl;
	matrix_dump(data);
}
