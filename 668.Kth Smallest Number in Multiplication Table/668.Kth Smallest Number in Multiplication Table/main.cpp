//
//  main.cpp
//  668.Kth Smallest Number in Multiplication Table
//
//  Created by stevenxu on 9/24/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int count = 0;
            pair<int, int> curr = {1, n};
            while (curr.first <= m && curr.second >= 1) {
                if (curr.first * curr.second <= mid) {
                    curr.first++;
                    count += curr.second;
                } else curr.second--;
            }
            if (count < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
