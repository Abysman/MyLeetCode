//
//  main.cpp
//  252.Meeting Rooms
//
//  Created by Abysman on 2018/11/1.
//  Copyright © 2018年 Abysman. All rights reserved.
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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start;});
        int last = intervals[0].end;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < last) return false;
            last = intervals[i].end;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
