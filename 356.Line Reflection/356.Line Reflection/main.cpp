//
//  main.cpp
//  356.Line Reflection
//
//  Created by Abysman on 2019/1/2.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int minx = INT_MAX, maxx = INT_MIN;
        map<int, set<int>> record;
        for (auto point:points) {
            if (point.first < minx) minx = point.first;
            if (point.first > maxx) maxx = point.first;
            record[point.first].insert(point.second);
        }
        double mid = (maxx + minx) * 1.0 / 2;
        for (auto point:points) {
            int reflection = 2 * mid - point.first;
            if (record.count(reflection) && record[reflection].count(point.second)) continue;
            else return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
