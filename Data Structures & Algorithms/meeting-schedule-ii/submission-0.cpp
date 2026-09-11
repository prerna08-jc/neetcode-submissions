/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        priority_queue<int,vector<int>,greater<int>> h;
        for (int i = 0; i < intervals.size(); i++) {
            if(!h.empty() && h.top()<=intervals[i].start){
                h.pop();
            }
            h.push(intervals[i].end);
        }
        return h.size();
    }
};
