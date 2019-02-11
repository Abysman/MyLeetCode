//
//  main.cpp
//  239.Sliding Window Maximum
//
//  Created by Abysman on 2019/2/10.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> buffer;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); ++i) {
            while (!buffer.empty() && nums[i] >= nums[buffer.back()]) buffer.pop_back();
            buffer.push_back(i);
            
            if (i >= k - 1) res.push_back(nums[buffer.front()]);
            if (i - buffer.front() >= k - 1) buffer.pop_front();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
