//
//  main.cpp
//  47.Permutations II
//
//  Created by Abysman on 2018/8/10.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

//  recursive 16ms
//class Solution {
//public:
//    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
//        if (i == j-1) {
//            res.push_back(num);
//            return;
//        }
//        for (int k = i; k < j; k++) {
//            if (i != k && num[i] == num[k]) continue;
//            swap(num[i], num[k]);
//            recursion(num, i+1, j, res);
//        }
//    }
//    vector<vector<int> > permuteUnique(vector<int> &num) {
//        sort(num.begin(), num.end());
//        vector<vector<int> >res;
//        recursion(num, 0, num.size(), res);
//        return res;
//    }
//};


//  also using map but 28ms
//class Solution {
//public:
//    vector<vector<int> > permuteUnique(vector<int> &num) {
//        vector<vector<int>> v;
//        vector<int> r;
//        map<int, int> map;
//        for (int i : num)
//        {
//            if (map.find(i) == map.end()) map[i] = 0;
//            map[i]++;
//        }
//        permuteUnique(v, r, map, num.size());
//        return v;
//    }
//
//    void permuteUnique(vector<vector<int>> &v, vector<int> &r, map<int, int> &map, int n)
//    {
//        if (n <= 0)
//        {
//            v.push_back(r);
//            return;
//        }
//        for (auto &p : map)
//        {
//            if (p.second <= 0) continue;
//            p.second--;
//            r.push_back(p.first);
//            permuteUnique(v, r, map, n - 1);
//            r.pop_back();
//            p.second++;
//        }
//    }
//};

//  using Next Permutation
//class Solution {
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> perms;
//        perms.push_back(nums);
//        while (nextPermutation(nums)) {
//            perms.push_back(nums);
//        }
//        return perms;
//    }
//private:
//    bool nextPermutation(vector<int>& nums) {
//        int n = nums.size(), k, l;
//        for (k = n - 2; k >= 0; k--) {
//            if (nums[k] < nums[k + 1]) {
//                break;
//            }
//        }
//        if (k < 0) {
//            reverse(nums.begin(), nums.end());
//            return false;
//        }
//        for (l = n - 1; l > k; l--) {
//            if (nums[l] > nums[k]) {
//                break;
//            }
//        }
//        swap(nums[k], nums[l]);
//        reverse(nums.begin() + k + 1, nums.end());
//        return true;
//    }
//};

//  mine    32ms
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) return vector<vector<int>> ();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        map<int, int> tmp;
        for (int i = 0; i < nums.size(); ++i) {
            tmp.insert(make_pair(nums[i], 0));
        }
        vector<map<int, int>> record(nums.size(), tmp);
        vector<int> index;
        vector<int> combination;
        helper(res, nums, combination, record, index);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& nums, vector<int> combination, vector<map<int, int>> record, vector<int> index) {
        if (combination.size() == nums.size()) {
            res.push_back(combination);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (record[combination.size()][nums[i]] != 1 && (find(index.begin(), index.end(), i) == index.end())) {
                record[combination.size()][nums[i]] = 1;
                combination.push_back(nums[i]);
                index.push_back(i);
            }
            else continue;
            helper(res, nums, combination, record, index);
            combination.pop_back();
            index.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,1,2,2};
    Solution sol = Solution();
    vector<vector<int>> res = sol.permuteUnique(a);
    
    for (int i = 0; i < res.size(); ++i){
        for (int j = 0; j < res[0].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    std::cout << "Hello, World!\n";
    return 0;
}
