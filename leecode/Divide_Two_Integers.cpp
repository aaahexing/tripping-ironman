class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        int sign = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        while (a >= b) {
            int c = 0;
            for (; (a >> c) >= b; ++c);
            a -= (b << (c - 1));
            ret += (1 << (c - 1));
        }
        return sign ? ret : -ret;
    }
};

