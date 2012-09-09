class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret = "";
        int num, carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        const int n = max(a.length(), b.length());
        for (int i = 0; i < n; ++i) {
            num = carry;
            if (i < a.length()) {
                num += a[i] - '0';
            }
            if (i < b.length()) {
                num += b[i] - '0';
            }
            carry = (num > 1 ? 1 : 0);
            num &= 1;
            ret += num + '0';
        }
        if (carry) {
            ret += "1";
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

