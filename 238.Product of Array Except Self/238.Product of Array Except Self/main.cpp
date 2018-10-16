//
//  main.cpp
//  238.Product of Array Except Self
//
//  Created by Abysman on 2018/10/6.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> fromBegin(n + 1, 1);
        vector<int> fromEnd(n + 1, 1);
        vector<int> res(n);
        
        for (int i = 1; i <= n; ++i) {
            fromBegin[i] = nums[i - 1] * fromBegin[i-1];
            fromEnd[i] = nums[n - i] * fromEnd[i-1];
        }
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = fromBegin[i] * fromEnd[n - i - 1];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
