//
//  main.cpp
//  436.Find Right Interval
//
//  Created by stevenxu on 9/24/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res;
        map<int, int> tmp;
        for (int i = 0; i < intervals.size(); ++i) {
            tmp[intervals[i][0]] = i;
        }
        for (vector<int> interval: intervals) {
            auto iter = tmp.lower_bound(interval[1]);
            if (iter != tmp.end()) res.push_back(iter->second);
            else res.push_back(-1);
        }
        return res;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
