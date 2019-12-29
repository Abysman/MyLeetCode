//
//  main.cpp
//  413.Arithmetic Slices
//
//  Created by stevenxu on 12/28/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n <= 2) return 0;
        int dp=0;
        
        int res = 0;
        for(int i=2; i<n; ++i){
            if(A[i]-A[i-1] == A[i-1]-A[i-2])
                ++dp;
            else
                dp=0;
            res += dp;
        }
        
        return res;
    }
};
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        A.push_back(INT_MIN);
        int n = A.size(), left = 0, right = 2;
        int count = 0;
        for (; right < n; ++right) {
            if (right == n - 1 || A[right] - A[right - 1] != A[right - 1] - A[right - 2]) {
                int curr = right - left;
                left = right - 1;
                if (curr == 2) continue;
                count += (curr - 2) * (curr - 1) / 2;
                
            }
        }
        return count;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
