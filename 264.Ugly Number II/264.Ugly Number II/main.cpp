//
//  main.cpp
//  264.Ugly Number II
//
//  Created by Abysman on 2019/1/8.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int nthUglyNumber(int n) {
        vector <int> record = {1};
        int i = 0, j = 0, k = 0;
        while (record.size() < n) {
            record.push_back(min(record[i] * 2, min(record[j] * 3, record[k] * 5)));
            if (record.back() == record[i] * 2) ++i;
            if (record.back() == record[j] * 3) ++j;
            if (record.back() == record[k] * 5) ++k;
        }
        return record.back();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
