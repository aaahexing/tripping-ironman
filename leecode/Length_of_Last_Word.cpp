class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pre = 0;
        int cur = 0;
        for (const char *p = s; *p != '\0'; ++p) {
            if (*p == ' ') {
                if (cur > 0) {
                    pre = cur;
                }
                cur = 0;
            } else {
                ++cur;
            }
        }
        return cur > 0 ? cur : pre;
    }
};

