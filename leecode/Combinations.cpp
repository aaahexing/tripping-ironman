class Solution {
public:
    int n;
    vector<int> a;
    vector< vector<int> > ret;
    void dfs(int i, int k) {
        if (a.size() == k) {
            ret.push_back(a);
        }
        if (i == n || a.size() >= k) {
            return;
        }
        // not use i
        dfs(i + 1, k);
        // use i
        a.push_back(i + 1);
        dfs(i + 1, k);
        a.pop_back();
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        a.clear();
        ret.clear();
        this->n = n;
        dfs(0, k);
        return ret;
    }
};

