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
        int n = intervals.size();
        if (n < 2) return intervals;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            if (a.start == b.start) return a.end < b.end;
            else return a.start < b.start;
        });
        vector<Interval> res;
        Interval prev = intervals[0];
        for (int i = 1; i < n; ++i) {
            Interval curr = intervals[i];
            if (curr.start > prev.end) {
                res.push_back(prev);
                prev = curr;
            }
            else if (curr.start <= prev.end && curr.end >= prev.end) {
                prev.end = curr.end;
            }
        }
        res.push_back(prev);
        return res;
    }
};




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
