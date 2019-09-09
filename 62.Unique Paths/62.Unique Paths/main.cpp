//
//  main.cpp
//  62.Unique Paths
//
//  Created by Abysman on 2018/8/12.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        if (m == 1 || n == 1) return 1;
        vector<int> record(m, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                record[j] = record[j - 1] + record[j];
            }
        }
        return record[m - 1];
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
