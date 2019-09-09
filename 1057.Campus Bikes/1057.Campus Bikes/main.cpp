//
//  main.cpp
//  1057.Campus Bikes
//
//  Created by stevenxu on 9/9/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int workers_num = workers.size(), bikes_num = bikes.size();
        vector<vector<pair<int, int>>> buckets(2001);
        for (int i = 0; i < workers_num; ++i) {
            for (int j = 0; j < bikes_num; ++j) {
                int distance = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                buckets[distance].push_back({i, j});
            }
        }
        vector<int> res(workers_num, -1);
        vector<bool> bikesUsed(bikes_num, false);
        for (int i = 0; i < 2001; ++i) {
            for (int j = 0; j < buckets[i].size(); ++j) {
                if (res[buckets[i][j].first] == -1 && bikesUsed[buckets[i][j].second] == false) {
                    res[buckets[i][j].first] = buckets[i][j].second;
                    bikesUsed[buckets[i][j].second] = true;
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
