class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &a) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> MP;
        vector<int> tri(3);
        vector< vector<int> > ret;
        const int n = a.size();
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            ++MP[a[i]];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int ak = -a[i] - a[j];
                int ck = 1;
                if (a[i] == ak) {
                    ++ck;
                }
                if (a[j] == ak) {
                    ++ck;
                }
                if (MP[ak] >= ck) {
                    tri[0] = a[i];
                    tri[1] = a[j];
                    tri[2] = ak;
                    sort(tri.begin(), tri.end());
                    bool dup = false;
                    for (int ii = 0; ii < (int)ret.size(); ++ii) {
                        if (ret[ii][0] == tri[0] && ret[ii][1] == tri[1] && ret[ii][2] == tri[2]) {
                            dup = true;
                            break;
                        }
                    }
                    if (!dup) {
                        ret.push_back(tri);
                    }
                }
            }
        }
        return ret;
    }
};

