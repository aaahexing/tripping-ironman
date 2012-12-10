class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ans = -1000000000, sum = 0;
        for (int i = 0; i < n; ++i) {
            if (sum < 0) {
                sum = 0;
            }
            sum += A[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};

