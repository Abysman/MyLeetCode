//
//  main.cpp
//  939.Minimum Area Rectangle
//
//  Created by stevenxu on 9/27/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> areas;
        int res = INT_MAX;
        for (vector<int> point: points) {
            areas[point[0]].insert(point[1]);
        }
        for (auto i = areas.begin(); i != areas.end(); ++i) {
            for (auto j = next(i); j != areas.end(); ++j) {
                if (i->second.size() < 2 || j->second.size() < 2) continue;
                vector<int> y;
                set_intersection(begin(i->second), end(i->second),
        begin(j->second), end(j->second), back_inserter(y));
                for (int k = 1; k < y.size(); ++k) {
                    res = min(res, abs(i->first - j->first) * (y[k] - y[k - 1]));
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
