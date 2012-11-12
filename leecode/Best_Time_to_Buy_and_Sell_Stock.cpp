class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = 0, mini = 2000000000;
        for (int i = 0; i < prices.size(); ++i) {
            ans = max(ans, prices[i] - mini);
            mini = min(prices[i], mini);
        }
        return ans;
    }
};

