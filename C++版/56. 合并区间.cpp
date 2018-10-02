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
    static bool compare(const Interval& a, const Interval& b){
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size() == 0)
            return res;
        sort(intervals.begin(), intervals.end(), compare);   //按start的顺序排序
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(res.back().end  >= intervals[i].start)
                res.back().end = max(res.back().end, intervals[i].end); //如果结果中的end大于遍历的start，那么有重合
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};