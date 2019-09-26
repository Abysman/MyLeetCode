//
//  main.cpp
//  598.Range Addition II
//
//  Created by stevenxu on 9/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (vector<int> op: ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m * n;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
