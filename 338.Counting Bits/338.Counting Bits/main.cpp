//
//  main.cpp
//  338.Counting Bits
//
//  Created by Abysman on 2018/9/16.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(1,0);
        for (int i = 1; i <= num; i++) {
            res.push_back(res[i & (i - 1)] + 1);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
