//
//  main.cpp
//  659.Split Array into Consecutive Subsequences
//
//  Created by stevenxu on 9/23/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if (nums.size() <= 2) return false;
        unordered_map<int, int> counts;
        unordered_map<int, int> tails;
        for (int num: nums) {
            counts[num] += 1;
        }
        for (int num: nums) {
            if (counts[num] == 0) continue;
            counts[num]--;
            if (tails[num - 1]) {
                tails[num - 1]--;
                tails[num]++;
            } else if (counts[num + 1] && counts[num + 2]) {
                counts[num + 1]--;
                counts[num + 2]--;
                tails[num + 2]++;
            } else return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
