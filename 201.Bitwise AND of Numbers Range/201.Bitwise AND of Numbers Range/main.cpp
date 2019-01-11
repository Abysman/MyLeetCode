//
//  main.cpp
//  201.Bitwise AND of Numbers Range
//
//  Created by Abysman on 2019/1/10.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>
//  referenced from https://leetcode.com/problems/bitwise-and-of-numbers-range/discuss/211810/C%2B%2B-O(32)-shift
//int rangeBitwiseAnd(int m, int n) {
//    int count = 0;
//    while(m != n){
//        m >>= 1;
//        n >>= 1;
//        count += 1;
//    }
//    return m <<= count;
//}

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n && n != 0) return m;
        if (n <= 1) return 0;
        int i = 0;
        while (pow(2, i + 1) <= m) i++;
        if (pow(2, i + 1) <= n) return 0;
        return pow(2, i) + rangeBitwiseAnd(m - pow(2, i), n - pow(2, i));
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
