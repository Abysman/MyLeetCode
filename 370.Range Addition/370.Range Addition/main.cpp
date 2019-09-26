//
//  main.cpp
//  370.Range Addition
//
//  Created by stevenxu on 9/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        int curr = 0;
        vector<int> tmp(length + 1), res;
        for (vector<int> update: updates) {
            tmp[update[0]] += update[2];
            tmp[update[1] + 1] -= update[2];
        }
        for (int i = 0; i < length; ++i) {
            curr += tmp[i];
            res.push_back(curr);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
