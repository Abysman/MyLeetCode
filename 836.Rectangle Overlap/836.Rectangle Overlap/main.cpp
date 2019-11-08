//
//  main.cpp
//  836.Rectangle Overlap
//
//  Created by stevenxu on 11/7/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x = max(rec1[0], rec2[0]) >= min(rec1[2], rec2[2]) ? 0 : min(rec1[2], rec2[2]) - max(rec1[0], rec2[0]);
        int y = max(rec1[1], rec2[1]) >= min(rec1[3], rec2[3]) ? 0 : min(rec1[3], rec2[3]) - max(rec1[1], rec2[1]);
        return (x != 0 && y != 0);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
