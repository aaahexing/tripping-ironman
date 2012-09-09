class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a = 0, b = 1, v = 1;
        for (int i = 1; i <= n; ++i) {
            v = a + b;
            a = b;
            b = v;
        }
        return v;
    }
};

