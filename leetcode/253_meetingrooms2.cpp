/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

typedef priority_queue<int, vector<int>, greater<int> > PQ;

bool cmp(const Interval &lhs, const Interval &rhs) {
    return lhs.start < rhs.start;
}

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        if (intervals.size() == 0)
            return 0;
        
        if (intervals.size() == 1)
            return 1;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int res = 0;
        PQ q;
        q.push(intervals[0].end);
        for(int i = 1; i < intervals.size(); ++i) {
            Interval cur = intervals[i];
            if (cur.start >= q.top()) {
                q.pop();
            }
            q.push(cur.end);
        }        
        return q.size();
    }
};

int main() {
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 8));
    intervals.push_back(Interval(6, 20));
    intervals.push_back(Interval(9, 16));
    intervals.push_back(Interval(13, 17));

    Solution s;
    cout << s.minMeetingRooms(intervals) << endl;

    return 0;
}
