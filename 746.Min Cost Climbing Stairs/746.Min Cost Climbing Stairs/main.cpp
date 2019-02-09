//
//  main.cpp
//  746.Min Cost Climbing Stairs
//
//  Created by Abysman on 2019/2/9.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> res(cost.size() + 1, 0);
        for (int i = 2; i <= cost.size(); ++i) {
            res[i] = min(res[i - 1] + cost[i - 1], res[i - 2] + cost[i - 2]);
        }
        return res[res.size() - 1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
