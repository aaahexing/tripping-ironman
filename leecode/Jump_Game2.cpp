#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int jump(int A[], int n) {
		vector<int> dp(n, n * n);
		set< pair<int, int> > S;
		dp[0] = 0;
		int maxi = 0 + A[0];
		S.insert(make_pair(0 + A[0], 0));
		for (int i = 1; i < n; ++i) {
			set< pair<int, int> > :: iterator it = lower_bound(S.begin(), S.end(), make_pair(i, 0));
			if (it != S.end()) {
				dp[i] = dp[it->second] + 1;
				if (i + A[i] > maxi) {
					maxi = i + A[i];
					S.insert(make_pair(i + A[i], i));
				}
			}
		}
		return dp[n - 1];
	}
};

int main() {
	Solution s;
	int vec[] = {1, 1, 3, 1, 1};
	printf("%d\n", s.jump(vec, 5));
	return 0;
}
