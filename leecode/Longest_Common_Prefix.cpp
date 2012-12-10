class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret = "";
        for (int i = 0; !strs.empty(); ++i) {
            bool ok = true;
            for (int j = 0; j < strs.size(); ++j) {
                if (i >= strs[j].length() || strs[j][i] != strs[0][i]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                break;
            }
            ret += strs[0][i];
        }
        return ret;
    }
};

