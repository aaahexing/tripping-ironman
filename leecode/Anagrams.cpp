#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(const string &a, const string &b) {
        string aa = a;
        string bb = b;
        sort(aa.begin(), aa.end());
        sort(bb.begin(), bb.end());
        return aa < bb;
    }
    static bool equal(const string &a, const string &b) {
        string aa = a;
        string bb = b;
        sort(aa.begin(), aa.end());
        sort(bb.begin(), bb.end());
        return aa == bb;
    }
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    int cc =  0;
	string pre = "";
        vector<string> ret;
        sort(strs.begin(), strs.end(), cmp);
        for (int i = 0; i < strs.size(); ++i) {
            if (i == 0 || !equal(strs[i], strs[i - 1])) {
                pre = strs[i];
                cc = 1;
            } else {
                if (cc) {
                    ret.push_back(pre);
                    cc = 0;
                }
                ret.push_back(strs[i]);
            }
        }
        return ret;
    }
};

int main() {
	return 0;
}

