class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        const int n = s1.length();
        const int m = s2.length();
        const int nn = s3.length();
        if (n + m != nn) {
            return false;
        }
        int *dp = new int[(n + 1) * (m + 1)];
        memset(dp, 0, sizeof(int) * (n + 1) * (m + 1));
        dp[0 * (m + 1) + 0] = 1;
        for (int l = 0; l < nn; ++l) {
            for (int i = 0; i <= l && i <= n; ++i) {
                int j = l - i;
                if (dp[i * (m + 1) + j] == 1) {
                    if (s3[l] == s1[i]) {
                        dp[(i + 1) * (m + 1) + j] = 1;
                    }
                    if (s3[l] == s2[j]) {
                        dp[i * (m + 1) + j + 1] = 1;
                    }
                }
            }
        }
        bool ret = dp[n * (m + 1) + m];
        delete [] dp;
        return ret;
    }
};

