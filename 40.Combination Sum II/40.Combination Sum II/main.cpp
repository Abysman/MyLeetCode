//
//  main.cpp
//  40.Combination Sum II
//
//  Created by Abysman on 2018/7/20.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        vector<vector<int>> res;
        subcombinationSum2(candidates, target, res, combination, 0);
        return res;
    }
    
    void subcombinationSum2(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i) {
            if (i == begin || candidates[i] != candidates[i-1]) {
                combination.push_back(candidates[i]);
                subcombinationSum2(candidates, target - candidates[i], res, combination, i+1);
                combination.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
