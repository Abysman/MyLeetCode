//
//  main.cpp
//  Subsets
//
//  Created by Abysman on 2018/3/16.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;
using std::cout;

class Solution {
public:
    vector<vector<int>> subsets_1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        vector<int> sub;
        subset_1(subsets, sub, 0, nums);
        return subsets;
    }
    
    void subset_1(vector<vector<int>>& subsets, vector<int>& sub, int start, const vector<int>& nums)
    {
        subsets.push_back(sub);
        
        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            subset_1(subsets, sub, i + 1, nums);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsets_2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            size_t n = subsets.size();
            for (int j = 0; j < n; j++) {
                vector<int> sub(subsets[j].begin(), subsets[j].end());
                sub.push_back(nums[i]);
                subsets.push_back(sub);
            }
        }
        return subsets;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1,2,3};
    Solution sol = Solution();
    vector<vector<int>> result = sol.subsets_2(nums);
    for (auto subset:result) {
        cout << "{";
        for (auto sub:subset) {
            cout << sub << " ";
        }
        cout << "}" << "\n";
    }
//    vector<int> nums = {1,2,3,4};
    
    cout << std::endl;
    return 0;
}
