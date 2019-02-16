//
//  main.cpp
//  977.Squares of a Sorted Array
//
//  Created by Abysman on 2019/2/15.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        deque<int> tmp;
        vector<int> res;
        if (A.empty()) return res;
        int i = 0, j = A.size() - 1;
        while (i <= j) {
            if (abs(A[i]) >= abs(A[j])) {
                tmp.push_front(A[i] * A[i]);
                i++;
            } else {
                tmp.push_front(A[j] * A[j]);
                j--;
            }
        }
        for (auto n: tmp) {
            res.push_back(n);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
