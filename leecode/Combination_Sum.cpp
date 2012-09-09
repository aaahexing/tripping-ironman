class Solution {
public:
    int n;
    vector<int> a;
    vector<int> buf;
    vector< vector<int> > ret;
    void dfs(int i, int sum, int tar) {
        if (sum == tar) {
            ret.push_back(buf);
        }
        if (i == n || sum >= tar) {
            return;
        }
        for (int j = 0; sum + a[i] * j <= tar; ++j) {
            for (int k = 0; k < j; ++k) {
                buf.push_back(a[i]);
            }
            dfs(i + 1, sum + a[i] * j, tar);
            for (int k = 0; k < j; ++k) {
                buf.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
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

