//
//  main.cpp
//  991.Broken Calculator
//
//  Created by stevenxu on 10/12/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(Y<=X) return X-Y;
        if(Y%2==0) return brokenCalc(X, Y/2)+1;
        else return brokenCalc(X, Y+1)+1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
