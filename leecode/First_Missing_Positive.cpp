class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> v(n + 1, false);
        for (int i = 0; i < n; ++i) {
            if (A[i] >= 1 && A[i] <= n) {
                v[A[i] - 1] = true;
            }
        }
        for (int i = 0; i < n + 1; ++i) {
            if (!v[i]) {
                return i + 1;
            }
        }
        return -1;
    }
};

