//
//  main.cpp
//  96.Unique Binary Search Trees
//
//  Created by Abysman on 2018/10/18.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int numTrees(int n) {
        std::vector<int> record(n + 1, 0);
        record[0] = 1;
        record[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                record[i] += record[j] * record[i - j - 1];
            }
        }
        return record[n];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
