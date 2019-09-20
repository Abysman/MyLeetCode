//
//  main.cpp
//  334.Increasing Triplet Subsequence
//
//  Created by stevenxu on 9/20/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX, c2 = INT_MAX;
        for (auto num: nums) {
            if (num <= c1) c1 = num;
            else if (num <= c2) c2 = num;
            else return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
