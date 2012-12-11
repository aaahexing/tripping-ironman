#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int> &num) {
		const int n = (int)num.size();
		for (int i = n - 1; i > 0; --i) {
			if (num[i] > num[i - 1]) {
				int mi = i;
				for (int j = i + 1; j < n; ++j) {
					if (mi == -1 || (num[j] > num[i - 1] && num[j] < num[mi])) {
						mi = j;
					}
				}
				swap(num[mi], num[i - 1]);
				sort(num.begin() + i, num.end());
				return;
			}
		}
		sort(num.begin(), num.end());
	}
};

void showVec(const vector<int> &num) {
	for (int i = 0; i < num.size(); ++i) {
		printf("%d ", num[i]);
	}
	puts("");
}

int main() {
	Solution s;
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	s.nextPermutation(num);
	showVec(num);

	return 0;
}
