//
//  main.cpp
//  442.Find All Duplicates in an Array
//
//  Created by Abysman on 2018/9/17.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (auto n:nums) {
            nums[abs(n) - 1] = - nums[abs(n) - 1];
            if (nums[abs(n) - 1] > 0) res.push_back(abs(n));
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
