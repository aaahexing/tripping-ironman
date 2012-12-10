class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        pair<int, int> opt = make_pair(-1, -1);
        const int n = s.length();
        // odd
        for (int p = 0; p < n; ++p) {
            pair<int, int> cur = make_pair(1, p);
            for (int x = 1; p - x >= 0 && p + x < n && s[p - x] == s[p + x]; ) {
                cur = make_pair(cur.first + 2, cur.second - 1);
                ++x;
            }
            if (cur.first > opt.first) {
                opt = cur;
            }
        }
        // even
        for (int p = 0; p + 1 < n; ++p) {
            if (s[p] == s[p + 1]) {
                pair<int, int> cur = make_pair(2, p);
                for (int x = 1; p - x >= 0 && p + 1 + x < n && s[p - x] == s[p + 1 + x]; ) {
                    cur = make_pair(cur.first + 2, cur.second - 1);
                    ++x;
                }
                if (cur.first > opt.first) {
                    opt = cur;
                }
            }
        }
        return s.substr(opt.second, opt.first);
    }
};

