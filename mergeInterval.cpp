/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


int cmp(const Interval &v1, const Interval &v2)
{
    if(v1.start < v2.start) return true;
    else if(v1.start == v2.start && v1.end < v2.end) return true;
    return false;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        int start = intervals[0].start, end = intervals[0].end;
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i].start <= end)
            {
                end = max(end, intervals[i].end);
            }
            else
            {
                Interval tmp(start, end);
                res.push_back(tmp);
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        Interval tmp(start, end);
        res.push_back(tmp);
        return res;
    }
};
