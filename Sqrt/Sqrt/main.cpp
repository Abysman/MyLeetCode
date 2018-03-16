//
//  main.cpp
//  Sqrt
//
//  Created by Abysman on 2018/3/16.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        long r = (x + 1) / 2;
        while (r*r > x) {
            r = (r + x/r) / 2;
        }
        return r;
//        int tmp = x / 2 + 1;
//        int result = 1.0 * (tmp + x/tmp) / 2;
//        while (tmp - result > 1) {
//            tmp = result;
//            result = 1.0 * (tmp + x/tmp) / 2;
//        }
//        while (result * result > x) {
//            result = result - 1;
//        }
//        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol = Solution();
    int num = 8;
    int result = sol.mySqrt(num);
    std::cout << result << std::endl;
    return 0;
}
