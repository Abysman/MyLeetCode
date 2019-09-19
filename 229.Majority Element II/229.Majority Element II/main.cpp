//
//  main.cpp
//  229.Majority Element II
//
//  Created by stevenxu on 9/19/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.empty()) return res;
        int a = 0, count_a = 0, b = 1, count_b = 0;
        for (auto num: nums) {
            if (num == a) {
                count_a++;
            } else if (num == b) {
                count_b++;
            } else if (count_a == 0) {
                a = num;
                count_a = 1;
            } else if (count_b == 0) {
                b = num;
                count_b = 1;
            } else {
                count_a--;
                count_b--;
            }
        }
        if (count(nums.begin(), nums.end(), a) > nums.size() / 3) res.push_back(a);
        if (count(nums.begin(), nums.end(), b) > nums.size() / 3) res.push_back(b);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
