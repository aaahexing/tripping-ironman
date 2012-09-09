class Solution {
public:
    static const int MAXN = 512;
    bool dp[MAXN][MAXN];
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        memset(dp, 0, sizeof(dp));
        int n = s1.length();
        int m = s2.length();
        if (s3.length() != n + m) {
            return false;
        }
        dp[0][0] = true;
        for (int s = 0; s < n + m; ++s) {
            for (int i = 0; i <= s; ++i) {
                int j = s - i;
                    if (dp[i][j]) {
                    // check the s3[s]
                    if (s3[s] == s1[i]) {
                        dp[i + 1][j] = true;
                    }
                    if (s3[s] == s2[j]) {
                        dp[i][j + 1] = true;
                    }                    
                }
            }
        }
        return dp[n][m];
    }
};

