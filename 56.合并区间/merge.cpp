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
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        if(intervals.size() == 1)
            return intervals;
        vector<Interval> res;
        int i = 0;
        while(i < intervals.size()){
            int start = intervals[i].start, end = intervals[i].end;
            int j = i+1;
            while(j < intervals.size() && intervals[j].start <= end){
                if(end < intervals[j].end)
                    end = intervals[j].end;
                j++;
            }
            struct Interval merge = {start, end};
            res.push_back(merge);
            i = j;
        }
        return res;
    }
    static bool cmp(Interval a, Interval b){
        return a.start < b.start;
    }
};