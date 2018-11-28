//
//  main.cpp
//  414.Third Maximum Number
//
//  Created by Abysman on 2018/11/28.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            s.insert(nums[i]);
            if (s.size() > 3) s.erase(s.begin());
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
