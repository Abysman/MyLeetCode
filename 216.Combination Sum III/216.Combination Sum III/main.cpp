//
//  main.cpp
//  216.Combination Sum III
//
//  Created by Abysman on 2018/11/25.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> sol;
        dfs(k, n, 1, res, sol);
        return res;
    }
    
    void dfs(int k, int n, int start, vector<vector<int>>& res, vector<int> sol) {
        if (k == 0) {
            if (n == 0) res.push_back(sol);
            return;
        }
        for (int i = start; i <= 9; ++i) {
            sol.push_back(i);
            dfs(k - 1, n - i, i + 1, res, sol);
            sol.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
