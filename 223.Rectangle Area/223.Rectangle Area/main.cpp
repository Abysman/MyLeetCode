//
//  main.cpp
//  223.Rectangle Area
//
//  Created by stevenxu on 11/4/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x = min(C, G) > max(A, E) ? min(C, G) - max(A, E) : 0;
        int y = min(D, H) > max(B, F) ? min(D, H) - max(B, F) : 0;
        return (C - A) * (D - B) - x * y + (G - E) * (H - F) ;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
