/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


bool cmp(const Interval &lhs, const Interval &rhs) {
    if (lhs.start != rhs.start)
        return lhs.start < rhs.start;
    return lhs.end > rhs.end;
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {        
        if (intervals.size() <= 1)
            return true;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < end) {
                return false;
            } else {
                end = max(end, intervals[i].end);
            }
        }
        return true;
    }
};
