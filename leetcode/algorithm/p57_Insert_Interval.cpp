/**
 * Insert Interval
 * Myyura
 */

/**
 * Given a set of non-overlapping intervals, insert a new interval into the 
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their 
 * start times.
 * 
 * Example 1:
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * Example 2:
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 * 
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
    /**
     * Find the position where newInterval should be inserted.
     * Merge the intervals as we do in problem 56.
     */
    std::vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval) {
        std::vector<Interval> result;
        auto itInsert = std::lower_bound(intervals.begin(), intervals.end(), newInterval,
                                        [](const Interval& a, const Interval& b) { return a.start < b.start; } );
        int indexInsert = std::distance(intervals.begin(), itInsert);
        
        if (indexInsert == 0) { result.push_back(newInterval); }
        for (int i = 0; i < intervals.size(); i++) {
            Interval current;
            if (i == indexInsert && i != 0) { 
                current = newInterval;
                indexInsert = -1;
                i--;
            } else { current = intervals[i]; }
            
            if (!result.empty() && current.start <= result.back().end) {
                result.back().end = std::max(current.end, result.back().end);
            } else { 
                result.push_back(current); 
            }
        }

        if (indexInsert != -1) {
            if (newInterval.start <= result.back().end) {
                result.back().end = std::max(newInterval.end, result.back().end);
            } else {
                result.push_back(newInterval);
            }
        }
        
        return result;
    }
};