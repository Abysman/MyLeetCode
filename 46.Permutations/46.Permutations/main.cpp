//
//  main.cpp
//  46.Permutations
//
//  Created by Abysman on 2018/7/20.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> permute;
        
        subpermute(nums,res, permute);
        return res;
    }
    
    void subpermute(vector<int>& nums, vector<vector<int>>& res, vector<int>& permute) {
        if (permute.size() == nums.size()) {
            res.push_back(permute);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if (find(permute.begin(), permute.end(), nums[i]) == permute.end()) permute.push_back(nums[i]);
            else continue;
            subpermute(nums, res, permute);
            permute.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
