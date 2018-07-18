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

//vector<vector<int> > threeSum(vector<int> &num) {
//    
//    vector<vector<int> > res;
//    
//    std::sort(num.begin(), num.end());
//    
//    for (int i = 0; i < num.size(); i++) {
//        
//        int target = -num[i];
//        int front = i + 1;
//        int back = num.size() - 1;
//        
//        while (front < back) {
//            
//            int sum = num[front] + num[back];
//            
//            // Finding answer which start from number num[i]
//            if (sum < target)
//                front++;
//            
//            else if (sum > target)
//                back--;
//            
//            else {
//                vector<int> triplet(3, 0);
//                triplet[0] = num[i];
//                triplet[1] = num[front];
//                triplet[2] = num[back];
//                res.push_back(triplet);
//                
//                // Processing duplicates of Number 2
//                // Rolling the front pointer to the next different number forwards
//                while (front < back && num[front] == triplet[1]) front++;
//                
//                // Processing duplicates of Number 3
//                // Rolling the back pointer to the next different number backwards
//                while (front < back && num[back] == triplet[2]) rear--;
//            }
//            
//        }
//        
//        // Processing duplicates of Number 1
//        while (i + 1 < num.size() && num[i + 1] == num[i])
//            i++;
//        
//    }
//    
//    return res;
//}

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
