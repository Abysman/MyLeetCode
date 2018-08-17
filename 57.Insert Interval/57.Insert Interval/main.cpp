//
//  main.cpp
//  57.Insert Interval
//
//  Created by Abysman on 2018/8/16.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
//  clean codes
//class Solution {
//public:
//    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
//        vector<Interval> res;
//        int index = 0;
//        while(index < intervals.size() && intervals[index].end < newInterval.start){
//            res.push_back(intervals[index++]);
//        }
//        while(index < intervals.size() && intervals[index].start <= newInterval.end){
//            newInterval.start = min(newInterval.start, intervals[index].start);
//            newInterval.end = max(newInterval.end, intervals[index].end);
//            index++;
//        }
//        res.push_back(newInterval);
//        while(index < intervals.size()){
//            res.push_back(intervals[index++]);
//        }
//        return res;
//    }
//};

//  mine
//  强行揉合在一起
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if (intervals.empty()) {
            res.push_back(newInterval);
            return res;
        }
        Interval curr = newInterval;
        for (int i = 0; i < intervals.size(); ++i) {
            if (curr.end >= curr.start) {
                if ((curr.start <= intervals[i].end) && (curr.start >= intervals[i].start)) {
                    curr.start = intervals[i].start;
                }
                else if (curr.start > intervals[i].end) {
                    res.push_back(intervals[i]);
                    continue;
                }
                
                if (curr.end < intervals[i].start) {
                    res.push_back(curr);
                    res.push_back(intervals[i]);
                    curr.end = curr.start - 1;
                }
                else if ((curr.end <= intervals[i].end) && (curr.end >= intervals[i].start)) {
                    curr.end = intervals[i].end;
                }
            }
            else {
                res.push_back(intervals[i]);
            }
        }
        if (curr.end >= curr.start) {
            res.push_back(curr);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
