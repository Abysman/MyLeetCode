//
//  main.cpp
//  253.Meeting Rooms II
//
//  Created by Abysman on 2019/2/11.
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
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
            return a.start < b.start;
        });
        priority_queue<int, vector<int>, greater<int>> record;
        int res = 1;
        record.push(intervals[0].end);
        for (int i = 1; i < intervals.size(); ++i) {
            if (record.top() <= intervals[i].start) record.pop();
            record.push(intervals[i].end);
            res = max(res, (int)record.size());
        }
        return res;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
