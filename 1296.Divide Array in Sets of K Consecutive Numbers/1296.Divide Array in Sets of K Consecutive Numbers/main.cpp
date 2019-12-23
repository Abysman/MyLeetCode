//
//  main.cpp
//  1296.Divide Array in Sets of K Consecutive Numbers
//
//  Created by stevenxu on 12/22/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (k <= 1) return true;
        if (n % k != 0) return false;
        map<int, int> record;
        for (int num: nums) record[num]++;
        for (auto elem: record) {
            int n = elem.first, curr = elem.second;
            if (curr == 0) continue;
            for (int i = n; i < k + n; ++i) {
                if (record[i] == 0) return false;
                record[i] -= curr;
            }
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
