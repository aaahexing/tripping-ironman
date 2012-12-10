class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        bool mark[26];
        queue< pair<int, int> > Q;
        memset(mark, false, sizeof(mark));
        for (int i = 0; i < s.length(); ++i) {
            if (mark[s[i] - 'a']) {
                while (!Q.empty()) {
                    int c = Q.front().first;
                    mark[c] = false;
                    Q.pop();
                    if (c == s[i] - 'a') {
                        break;
                    }
                }
            }
            Q.push(make_pair(s[i] - 'a', i));
            mark[s[i] - 'a'] = true;
            ret = max(ret, i - Q.front().second + 1);
        }
        return ret;
    }
};

