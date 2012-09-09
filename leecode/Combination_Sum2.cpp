class Solution {
public:
    int n;
    vector<int> a;
    vector<int> buf;
    vector< vector<int> > ret;
    void dfs(int i, int sum, int tar) {
        if (sum == tar) {
            bool dup = false;
            for (int ii = 0; ii < ret.size(); ++ii) {
                bool equal = ret[ii].size() == buf.size();
                for (int i = 0; equal && i < buf.size(); ++i) {
                    if (buf[i] != ret[ii][i]) {
                        equal = false;
                        break;
                    }
                }
                if (equal) {
                    dup = true;
                    break;
                }
            }
            if (!dup) {
                ret.push_back(buf);
            }
        }
        if (i == n || sum >= tar) {
            return;
        }
        // not use a[i]
        dfs(i + 1, sum, tar);
        // use a[i]
        buf.push_back(a[i]);
        dfs(i + 1, sum + a[i], tar);
        buf.pop_back();
    }
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(), candidates.end());
        a = candidates;
        n = candidates.size();
        buf.clear(), ret.clear();
        dfs(0, 0, target);
        return ret;
    }
};

