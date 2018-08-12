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
        vector<int> record(n, 1);
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    record[0] = 1;
                    continue;
                }
                record[j] = record[j - 1] + record[j];
            }
        }
        return record[n - 1];
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
