//
//  main.cpp
//  134.Gas Station
//
//  Created by Abysman on 2018/10/2.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        if (gas.empty() || (gas.size() == 1 && gas[0] >= cost[0])) return 0;
        std::vector<int> record(gas.size(), 0);
        int n = gas.size();
        for (int i = 0; i < n; ++i) {
            if (gas[i] < cost[i]) {
                continue;
            }
            if (record[i - 1] == -1) {
                record[i] = -1;
                continue;
            }
            int curr = (i == n - 1 ? 0 : i + 1);
            int tmp = gas[i] - cost[i];
            while (curr != i) {
                tmp += gas[curr] - cost[curr];
                if (tmp < 0) {
                    record[i] = -1;
                    break;
                }
                curr++;
                if (curr == gas.size()) curr = 0;
            }
            if (curr == i) return i;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
