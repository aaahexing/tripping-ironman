/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    inline bool overlap(const Interval &l, const Interval &r) {
        return !(l.start > r.end || l.end < r.start);
    }
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool add = false;
        vector<Interval> ret;
        for (int i = 0; i < intervals.size(); ++i) {
            if (!overlap(newInterval, intervals[i])) {
                if (!add && newInterval.end < intervals[i].start) {
                    add = true;
                    ret.push_back(newInterval);
                }
                ret.push_back(intervals[i]);
            } else {
                int p = i;
                for (; p < intervals.size() && overlap(newInterval, intervals[p]); ++p) {
                    newInterval.start = min(newInterval.start, intervals[p].start);
                    newInterval.end = max(newInterval.end, intervals[p].end);
                }
                add = true;
                ret.push_back(newInterval);
                for (int j = 0; p + j < intervals.size(); ++j) {
                    ret.push_back(intervals[p + j]);
                }
                break;
            }
        }
        if (!add) {
            ret.push_back(newInterval);
        }
        return ret;
    }
};

