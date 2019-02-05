//
//  main.cpp
//  277.Find the Celebrity
//
//  Created by Abysman on 2019/2/5.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 1; i < n; ++i) {
            if (!knows(i, candidate)) candidate = i;
        }
        
        for (int j = 0; j < n; ++j) {
            if (j == candidate) continue;
            if (!knows(j, candidate) || knows(candidate, j)) return -1;
        }
        
        return candidate;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
