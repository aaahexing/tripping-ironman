class Solution {
public:
    int threeSumClosest(vector<int> &a, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int mini = 2000000000, ans = -1;
        sort(a.begin(), a.end());
        const int n = a.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<int>::iterator it = lower_bound(a.begin() + j + 1, a.end(), target - a[i] - a[j]);
                if (it != a.end()) {
                    int k = it - a.begin();
                    if (mini > a[i] + a[j] + a[k] - target) {
                        mini = a[i] + a[j] + a[k] - target;
                        ans = a[i] + a[j] + a[k];
                    }
                }
                it = upper_bound(a.begin() + j + 1, a.end(), target - a[i] - a[j]);
                if (it > a.begin() + j + 1) {
                    --it;
                    int k = it - a.begin();
                    if (mini > target - a[i] - a[j] - a[k]) {
                        mini = target - a[i] - a[j] - a[k];
                        ans = a[i] + a[j] + a[k];
                    }
                }
            }
        }
        return ans;
    }
};

