#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int ans = 0;
        const int row = matrix.size();
        const int col = matrix[0].size();
        vector<int> h(col, 0), left(col), right(col);
        for (int r = 0; r < row; ++r) {
            // calculate height
            for (int i = 0; i < col; ++i) {
                h[i] = matrix[r][i] == '1' ? h[i] + 1 : 0;
            }
            for (int i = 0; i < col; ++i) {
                int j = i;
                while (j > 0 && h[j - 1] >= h[i]) {
                    j = left[j - 1];
                }
                left[i] = j;
            }
            for (int i = col - 1; i >= 0; --i) {
                int j = i;
                while (j + 1 < col && h[j + 1] >= h[i]) {
                    j = right[j + 1];
                }
                right[i] = j;
            }
            for (int i = 0; i < col; ++i) {
                ans = max(ans, h[i] * (right[i] - left[i] + 1));
            }
        }
        return ans;
    }
};

int main() {
	Solution s;
	vector< vector<char> > rec;
	vector<char> tmp;
	tmp.push_back('1');
	rec.push_back(tmp);
	cout << s.maximalRectangle(rec) << endl;
	return 0;
}
