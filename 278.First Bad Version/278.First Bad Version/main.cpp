//
//  main.cpp
//  278.First Bad Version
//
//  Created by Abysman on 2018/8/9.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int h = n;
        while (l != h) {
            cout << l << " " << h << "\n";
            int mid = l + (h - l) / 2;
            if (isBadVersion(mid) == true) {
                h = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
