//
//  main.cpp
//  453.Minimum Moves to Equal Array Elements
//
//  Created by Abysman on 2018/12/31.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) return 0;
        int n = nums.size();
        int sum = 0;
        int min = INT_MAX;
        for (auto n:nums) {
            min = (min >= n ? n : min);
            sum += n;
        }
        return (sum - min * n);
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
