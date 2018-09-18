//
//  main.cpp
//  448.Find All Numbers Disappeared in an Array
//
//  Created by Abysman on 2018/9/17.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (auto n:nums) {
            nums[abs(n) - 1] = nums[abs(n) - 1] > 0 ?  -nums[abs(n) - 1] : nums[abs(n) - 1];
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
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
