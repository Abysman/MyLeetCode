//
//  main.cpp
//  90.Subsets II
//
//  Created by Abysman on 2019/2/18.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        if (nums.empty()) return res;
        sort(nums.begin(), nums.end());
        helper(nums, res, curr, 0);
        return res;
    }
    
    void helper(vector<int> nums, vector<vector<int>>& res, vector<int> &curr, int start){
        res.push_back(curr);
        for (int i = start; i < (int)nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            helper(nums, res, curr, i + 1);
            curr.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> a = {1};
    vector<int> b = {1};
    set<vector<int>> t;
    t.insert(a);
    if (t.find(b) == t.end()) cout << "????" << "\n";
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
