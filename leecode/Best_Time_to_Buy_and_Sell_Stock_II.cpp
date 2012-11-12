class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const int n = prices.size();
    	int maxi = -1000000000;
        vector<int> dp(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			dp[i] = max(maxi + prices[i - 1], dp[i - 1]);
			maxi = max(maxi, dp[i - 1] - prices[i - 1]);
		}
        return dp[n];
    }
};

