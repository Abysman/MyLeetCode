//
//  main.cpp
//  254.Factor Combinations
//
//  Created by Abysman on 2018/11/15.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>


//  In the incrementing order
class Solution {
public:
    std::vector<std::vector<int>> getFactors(int n) {
        std::vector<std::vector<int>> res;
        std::vector<int> sol;
        helper(n, 2, sol, res);
        return res;
    }
    
    void helper(int n, int f, std::vector<int>& sol, std::vector<std::vector<int>>& res) {
        for (int i = f; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                sol.push_back(i);
                sol.push_back(n / i);
                res.push_back(sol);
                sol.pop_back();
                helper(n/i, i, sol, res);
                sol.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
