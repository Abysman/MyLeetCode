//
//  main.cpp
//  26.Remove Duplicates from Sorted Array
//
//  Created by Abysman on 2018/8/1.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i < n; i++){
            if(A[i] == A[i-1]) count++;
            else A[i-count] = A[i];
        }
        return n-count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
