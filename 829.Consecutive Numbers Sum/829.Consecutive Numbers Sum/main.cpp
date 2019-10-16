//
//  main.cpp
//  829.Consecutive Numbers Sum
//
//  Created by stevenxu on 10/15/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0;
        for (int m = 1; ; m++) {
            int mx = N - m * (m-1) / 2;
            if (mx <= 0)
                break;
            if (mx % m == 0)
                ans++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
