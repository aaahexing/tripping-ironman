class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if (n == 0) {
            ret.push_back(0);
        } else {
            ret = grayCode(n - 1);
            vector<int> nxt = ret;
            reverse(nxt.begin(), nxt.end());
            for (int i = 0; i < nxt.size(); ++i) {
                nxt[i] |= (1 << (n - 1));
            }
            ret.insert(ret.end(), nxt.begin(), nxt.end());
        }
        return ret;
    }
};

