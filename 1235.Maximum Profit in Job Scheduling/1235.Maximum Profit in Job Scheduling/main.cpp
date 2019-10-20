//
//  main.cpp
//  1235.Maximum Profit in Job Scheduling
//
//  Created by stevenxu on 10/19/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;;

class Solution {

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> record;
        for (int i = 0; i < n; ++i) {
            record.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(record.begin(), record.end(), [](auto &aa, auto &bb){return aa[1]<bb[1];});
        vector<int> tmp(n);
        tmp[0] = record[0][2];
        for (int i = 1; i < n; ++i) {
            int currProfit = record[i][2];
            int last = -1;
            for (int j = i - 1; j >= 0; --j) {
                if (record[j][1] <= record[i][0]) {
                    last = j;
                    break;
                }
            }
            if (last != -1) currProfit += tmp[last];
            tmp[i] = max(currProfit, tmp[i - 1]);
        }
        return tmp[n - 1];
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
