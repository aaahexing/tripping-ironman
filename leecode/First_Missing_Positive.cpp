class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (A[i] <= 0 || A[i] > n + 1) {
                continue;
            }
            v[A[i] - 1] = 1;
        }
        for (int i = 0; i < n + 1; ++i) {
            if (!v[i]) {
                return i + 1;
            }
        }
        return -1;
    }
};

