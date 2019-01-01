//
//  main.cpp
//  001.Minimum unique array sum
//
//  Created by Abysman on 2019/1/1.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>


// Given a sorted integer array, return sum of array so that each element is unique by adding some numbers to duplicate elements so that sum of unique elements is minimum.

int minUniqueSum(std::vector<int> A) {
    int s = A.size();
    int sum = A[0];
    int prev = A[0];
    
    for (int i = 1; i < s; ++i) {
        int curr = A[i];
        if (prev >= curr) {
            curr = prev + 1;
        }
        sum += curr;
        prev = curr;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
