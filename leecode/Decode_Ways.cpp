class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s == "") {
            return 0;
        }
        const int n = s.length();
        vector<int> dp(n + 1);
        memset(&dp[0], 0, sizeof(int) * (n + 1));
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            // x
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }
            if (i >= 2) {
                if (s[i - 2] == '1') {
                    // 1x
                    dp[i] += dp[i - 2];
                } else if (s[i - 2] == '2' && s[i - 1] <= '6') {
                    // 2x
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[n];
    }
};

