//
//  main.cpp
//  1133.Largest Unique Number
//
//  Created by stevenxu on 12/1/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        vector<int> a(1001);
        int i = 0;
        for (auto n : A) ++a[n];
        for (i = 1000; i >= 0 && a[i] != 1; --i);
        return i;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
