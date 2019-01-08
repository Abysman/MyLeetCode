//
//  main.cpp
//  435.Non-overlapping Intervals
//
//  Created by Abysman on 2019/1/7.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](Interval i1, Interval i2){return i1.end < i2.end;});
        int count = 0;
        int prev = intervals[0].end;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < prev) count += 1;
            else prev = intervals[i].end;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
