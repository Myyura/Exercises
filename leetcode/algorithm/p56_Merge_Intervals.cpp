/**
 * Merge Intervals
 * Myyura
 */

/**
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 * 
 * Example 2:
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
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
    std::vector<Interval> merge(std::vector<Interval>& intervals) {
        std::vector<Interval> result;
        if (intervals.empty()) { return result; }
        
        std::vector<Interval> intervalsSorted(intervals);
        std::sort(intervalsSorted.begin(), intervalsSorted.end(), 
                  [](const Interval& a, const Interval& b) { return a.start < b.start; });
        
        Interval previous = intervalsSorted[0];
        for (int i = 0; i < intervalsSorted.size(); i++) {
            if (!result.empty() && intervalsSorted[i].start <= result.back().end) {
                result.back().end = std::max(intervalsSorted[i].end, result.back().end);
            } else {
                result.push_back(intervalsSorted[i]);
            }
        }

        return result;
    }
};