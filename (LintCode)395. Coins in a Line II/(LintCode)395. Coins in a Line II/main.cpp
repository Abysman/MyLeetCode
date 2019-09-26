//
//  main.cpp
//  (LintCode)395. Coins in a Line II
//
//  Created by stevenxu on 9/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//
#include <iostream>

class Solution {
public:
    bool firstWillWin(vector<int> &values) {
        int n = values.size();
        if (n < 3)
            return true;
            
        vector<int> sum(n, 0), f(n, 0);
        
        f[n-1] = sum[n-1] = values[n-1];
        f[n-2] = sum[n-2] = values[n-1] + values[n-2];
        for (int i = n-3; i >= 0; i--)
        {
            sum[i] = sum[i+1] + values[i];
            f[i] = max(
                sum[i+1] - f[i+1] + values[i],
                sum[i+2] - f[i+2] + values[i] + values[i+1]
            );
        }
        
        return f[0] > sum[0] - f[0];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
