//
//  main.cpp
//  169.Majority Element
//
//  Created by stevenxu on 9/19/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counts;
        for (int num: nums) {
            counts[num]++;
            if (counts[num] > n / 2) return num;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
