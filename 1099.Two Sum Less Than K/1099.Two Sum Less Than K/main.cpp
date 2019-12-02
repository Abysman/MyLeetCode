//
//  main.cpp
//  1099.Two Sum Less Than K
//
//  Created by stevenxu on 12/1/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
   int twoSumLessThanK(vector<int>& A, int K, int S = -1) {
        sort(begin(A), end(A));
        for (int i = 0, j = A.size() - 1; i < j; ) {
            if (A[i] + A[j] < K) S = max(S, A[i++] + A[j]);
            else --j;
        }
        return S;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
