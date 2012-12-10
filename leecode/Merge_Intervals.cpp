/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(const Interval &a, const Interval &b) {
    if (a.start != b.start) {
        return a.start < b.start;
    } else {
        return a.end < b.end;
    }
}

class Solution {
public:
    bool overlap(const Interval &a, const Interval &b) {
        return a.end >= b.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < intervals.size(); ++i) {
            if (!ret.empty() && overlap(ret.back(), intervals[i])) {
                Interval nxt;
                nxt.start = min(ret.back().start, intervals[i].start);
                nxt.end = max(ret.back().end, intervals[i].end);
                ret.pop_back();
                ret.push_back(nxt);
            } else {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};

