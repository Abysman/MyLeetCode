//
//  main.cpp
//  35.Search Insert Position
//
//  Created by Abysman on 2018/7/23.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert_2(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        
        // Invariant: the desired index is between [low, high+1]
        while (low <= high) {
            int mid = low + (high-low)/2;
            
            if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        
        // (1) At this point, low > high. That is, low >= high+1
        // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
        // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
        //     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
        return low;
    }
    //  mine
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return nums.size();
        if (nums[0] >= target) return 0;
        int last = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) return i;
            if (last < target && nums[i] > target) return i;
            last = nums[i];
        }
        return nums.size();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
