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
    
    // Approach #1
    /*
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), cmp);
        for(int i = 0; i < intervals.size(); ++i) {
            int start = intervals[i].start;
            int end = intervals[i].end;
            int j;
            for(j = i + 1; j < intervals.size(); ++j) {
                if (intervals[j].start >= start && intervals[j].start <= end) {
                    end = max(end, intervals[j].end);
                } else {
                    break;
                }
            }
            res.push_back(Interval(start, end));
            i = j - 1;
        }
        return res;
    }
    */

    // Approach #2
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0)
            return intervals;
        
        sort(intervals.begin(), intervals.end(), cmp);

        int start = intervals[0].start;
        int end = intervals[0].end;
        vector<Interval> res;        
        for(int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= end) {
                end = max(end, intervals[i].end);
            } else {
                res.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        res.push_back(Interval(start, end));        
        return res;
    }
    
};
