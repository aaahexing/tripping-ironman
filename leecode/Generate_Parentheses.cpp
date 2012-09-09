class Solution {
public:
    vector<string> gao(int n) {
        vector<string> ret;
        if (n == 1) {
            ret.push_back("()");
        } else {
            vector<string> buf;
            vector<string> pre = gao(n - 1);
            for (int i = 0; i < pre.size(); ++i) {
                buf.push_back(string("(") + pre[i] + string(")"));
            }
            for (int i = 1; n - i >= 1; ++i) {
                vector<string> left = gao(i);
                vector<string> right = gao(n - i);
                for (int li = 0; li < left.size(); ++li) {
                    for (int ri = 0; ri < right.size(); ++ri) {
                        buf.push_back(left[li] + right[ri]);
                    }
                }
            }
            sort(buf.begin(), buf.end());
            for (int i = 0; i < buf.size(); ++i) {
                if (i == 0 || buf[i] != buf[i - 1]) {
                    ret.push_back(buf[i]);
                }
            }
        }
        return ret;
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return gao(n);
    }
};

