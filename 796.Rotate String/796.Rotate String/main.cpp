//
//  main.cpp
//  796.Rotate String
//
//  Created by Abysman on 2019/1/29.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() != B.length()) return false;
        if (A.length() == 0) return true;
        A += A;
        if (A.find(B) != string::npos) return true;
        else return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
