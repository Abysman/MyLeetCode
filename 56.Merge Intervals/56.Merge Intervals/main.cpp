//
//  main.cpp
//  56.Merge Intervals
//
//  Created by Abysman on 2018/8/12.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//vector<Interval> merge(vector<Interval>& ins) {
//    if (ins.empty()) return vector<Interval>{};
//    vector<Interval> res;
//    sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
//    res.push_back(ins[0]);
//    for (int i = 1; i < ins.size(); i++) {
//        if (res.back().end < ins[i].start) res.push_back(ins[i]);
//        else
//            res.back().end = max(res.back().end, ins[i].end);
//    }
//    return res;
//}

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
        if (intervals.empty()) return vector<Interval> ();
        intervals.push_back(Interval(INT_MAX, INT_MAX));
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        Interval curr = intervals[0];
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (curr.end < intervals[i].start) {
                res.push_back(curr);
                curr = intervals[i];
            }
            else {
                if (curr.end < intervals[i].end) {
                    curr.end = intervals[i].end;
                }
            }
        }
        return res;
    }
};




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
