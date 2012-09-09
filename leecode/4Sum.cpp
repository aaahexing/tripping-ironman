class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &a, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> qua(4);
        vector< vector<int> > ret;
        sort(a.begin(), a.end());
        const int n = a.size();
        map<int, vector< pair<int, int> > > MP;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                MP[a[i] + a[j]].push_back(make_pair(i, j));
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = target - a[i] - a[j];
                const vector< pair<int, int> > &vec = MP[sum];
                for (int ii = 0; ii < vec.size(); ++ii) {
                    if (vec[ii].first != i && vec[ii].first != j && vec[ii].second != i && vec[ii].second != j) {
                        qua[0] = a[i];
                        qua[1] = a[j];
                        qua[2] = a[vec[ii].first];
                        qua[3] = a[vec[ii].second];
                        sort(qua.begin(), qua.end());
                        bool dup = false;
                        for (int jj = 0; jj < ret.size(); ++jj) {
                            bool eq = true;
                            for (int k = 0; k < 4; ++k) {
                                if (qua[k] != ret[jj][k]) {
                                    eq = false;
                                    break;
                                }
                            }
                            if (eq) {
                                dup = true;
                                break;
                            }
                        }
                        if (!dup) {
                            ret.push_back(qua);
                        }
                    }
                }
            }
        }
        return ret;
    }
};

