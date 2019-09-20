//
//  main.cpp
//  220.Contains Duplicate III
//
//  Created by stevenxu on 9/20/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) window.erase(nums[i-k-1]);
            auto pos = window.lower_bound((long)nums[i] - t);
            if (pos != window.end() && *pos - nums[i] <= t) return true;
            window.insert(nums[i]);
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
