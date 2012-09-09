class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string cur = "1";
        for (int i = 1; i < n; ++i) {
            int cc = 0;
            char ch = '?';
            string nxt = "";
            for (int j = 0; j < cur.length(); ++j) {
                if (j == 0 || cur[j] != cur[j - 1]) {
                    ch = cur[j];
                    cc = 1;
                } else {
                    ++cc;
                }
                if (j + 1 == cur.length() || cur[j] != cur[j + 1]) {
                    if (cc > 0) {
                        nxt += '0' + cc;
                        nxt += ch;
                        cc = 0;
                    }
                }
            }
            cur = nxt;
        }
        return cur;
    }
};

