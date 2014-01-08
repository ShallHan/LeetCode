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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int pos = 0;
        for(; pos < intervals.size(); ++pos)
        {
            if(newInterval.start <= intervals[pos].start)
                break;
        }
        intervals.insert(intervals.begin() + pos, newInterval);
        //combine overlap
        pos = 0;
        while(pos < intervals.size() - 1)
        {
            if(intervals[pos].end < intervals[pos + 1].start)
            {
                pos++;
                continue;
            }
            intervals[pos].end = max(intervals[pos].end, intervals[pos + 1].end);
            intervals.erase(intervals.begin() + pos + 1);
        }
        return intervals;
    }
};
