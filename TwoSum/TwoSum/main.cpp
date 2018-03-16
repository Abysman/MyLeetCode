//
//  main.cpp
//  TwoSum
//
//  Created by Abysman on 2018/2/9.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> record;
    for (int i = 0; i != nums.size(); ++i) {
        auto found = record.find(nums[i]);
        if (found != record.end()) {
            return {found->second, i};
        }
        record.emplace(target - nums[i], i);
    }
    
    sort(nums.begin(), nums.end());
    
    return {-1, -1};
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
}
