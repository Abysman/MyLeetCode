//
//  main.cpp
//  331.Verify Preorder Serialization of a Binary Tree
//
//  Created by stevenxu on 11/5/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int outDegrees = 1;
        stringstream ss(preorder);
        string curr;
        while (getline(ss, curr, ',')) {
            if (--outDegrees < 0) return false;
            if (curr[0] != '#') outDegrees += 2;
        }
        return outDegrees == 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
