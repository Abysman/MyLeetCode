//
//  main.cpp
//  533.Two Sum - Closest to target(Lintcode)
//
//  Created by Abysman on 2019/1/29.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int twoSumClosest(vector<int> nums, int target) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return abs(nums[0] - target);
    sort(nums.begin(), nums.end());
    int low = 0, high = nums.size() - 1;
    int diff = INT_MAX;
    while (low < high) {
        int sum = nums[low] + nums[high];
        if (sum > target) high--;
        else low++;
        diff = min(diff, abs(sum - target));
    }
    return diff;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1};
    int target = 4;
    cout << twoSumClosest(nums, target) << "\n";
    std::cout << "Hello, World!\n";
    return 0;
}
