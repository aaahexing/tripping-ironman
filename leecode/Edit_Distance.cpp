class Solution {
public:
    static const int MAXN = 512;
    int dp[MAXN][MAXN];
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = word1.length();
        int m = word2.length();
        memset(dp, 0x3f, sizeof(int) * MAXN * MAXN);
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // no-operation
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                } else {
                    // replace
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);                    
                }
                // add word1
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                // delete word1
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
        }
        return dp[n][m];
    }
};

