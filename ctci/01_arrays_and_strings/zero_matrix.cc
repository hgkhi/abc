#include <bits/stdc++.h>
using namespace std;

/**
 * Runtime: O(n*m + n + m)
 * Space: O(n + m)
 */
void zero_matrix(vector<vector<int>>& data)
{
	unordered_set<size_t> cols, rows;

	for (size_t i = 0; i < data.size(); ++i) {
		for (size_t j = 0; j < data[0].size(); ++j) {
			if (data[i][j] == 0) {
				rows.insert(i);
				cols.insert(j);
			}
		}
	}

	for (size_t it : rows) {
		for (size_t i = 0; i < data[0].size(); ++i) {
			data[it][i] = 0;
		}
	}

	for (size_t it : cols) {
		for (size_t i = 0; i < data.size(); ++i) {
			data[i][it] = 0;
		}
	}
}

void matrix_dump(vector<vector<int>> matrix)
{
	size_t size = matrix.size();
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << matrix[i][j] << "\t";
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
	data[2][3] = 0;

	matrix_dump(data);
	zero_matrix(data);
	cout << endl;
	matrix_dump(data);
}
