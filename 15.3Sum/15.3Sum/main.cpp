//
//  main.cpp
//  15.3Sum
//
//  Created by Abysman on 2018/5/2.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, h = n - 1;
            while (l < h) {
                int currSum = nums[l] + nums[h] + nums[i];
                if (currSum < 0) l++;
                else if (currSum > 0) h--;
                else {
                    res.push_back({nums[i], nums[l], nums[h]});
                    while (l < h && nums[l + 1] == nums[l]) l++;
                    while (l < h && nums[h - 1] == nums[h]) h--;
                    l++;h--;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        if (!nums.empty()) {
            int last = nums[nums.size() - 1] + 1;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] != last && nums[i] <= 0) {
                    vector<int> tmp(nums.begin() + i + 1, nums.end());
                    twoSum(sol, tmp, -nums[i]);
                }
                last = nums[i];
            }
        }
        return sol;
    }
    
    void twoSum(vector<vector<int>>& sol, vector<int>& nums, int sum) {
        vector<int> solution = {-sum};
        map<int, int> tmp_map;
        for (int i = 0; i != nums.size(); ++i) {
            auto found = tmp_map.find(nums[i]);
            if (found != tmp_map.end()) {
                if (found->second >= 0 && found->second < nums.size()){
                    solution.push_back(nums[found->second]);
                    solution.push_back(nums[i]);
                    tmp_map.erase(found);
                    tmp_map[found->first] = INT_MIN;
                    tmp_map.insert(make_pair(nums[i], INT_MIN));
                    sol.push_back(solution);
                    solution.pop_back();
                    solution.pop_back();
                }
            }
            else {
                tmp_map.insert(make_pair(sum - nums[i], i));
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> input = {-1,0,1,2,-1,-4};
    vector<int> input2 = {0,0,0,0};
    Solution sol = Solution();
    vector<vector<int>> output = sol.threeSum(input);
    cout << "\n";
    for (auto& t:output) {
        for (auto& d:t) {
            cout << d << " ";
        }
        cout << "\n";
    }
    cout << endl;
//    unordered_map<int, int> tmp_map;
//    tmp_map.emplace(0, 1);
//    auto found = tmp_map.find(0);
//    tmp_map.emplace(0,2);
//    cout << found->second <<endl;
    
    return 0;
}
