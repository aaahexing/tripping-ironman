class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const int m = grid.size();
        const int n = grid[0].size();
        vector< vector<int> > dp(m);
        for (int i = 0; i < m; ++i) {
            dp[i] = vector<int>(n, 0x3f3f3f3f);
        }
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // move right
                if (j + 1 < n) {
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + grid[i][j + 1]);                    
                }
                // move down
                if (i + 1 < m) {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + grid[i + 1][j]);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

