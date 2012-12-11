#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> row[2];
		for (int i = 0; i <= rowIndex; ++i) {
			int cur = i & 1;
			int pre = 1 - cur;
			row[cur].clear();
			for (int j = 0; j <= i; ++j) {
				if (j == 0 || j == i) {
					row[cur].push_back(1);
				} else {
					row[cur].push_back(row[pre][j - 1] + row[pre][j]);
				}
			}
		}
		return row[rowIndex & 1];
	}
};

int main() {
	return 0;
}
