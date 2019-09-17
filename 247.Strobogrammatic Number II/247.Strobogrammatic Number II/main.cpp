//
//  main.cpp
//  247.Strobogrammatic Number II
//
//  Created by stevenxu on 9/17/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;;

class Solution {
    vector<pair<char, char>> tmp = {{'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        string curr = "";
        for (int i = 0;i < n; ++i) curr += "0";
        dfs(res, curr, 0, n - 1);
        return res;
    }
    
    void dfs(vector<string>& res, string curr, int left, int right) {
        if (left == right) {
            curr[left] = '0';
            res.push_back(curr);
            curr[left] = '1';
            res.push_back(curr);
            curr[left] = '8';
            res.push_back(curr);
        } else if (left > right) {
            res.push_back(curr);
        } else {
            for (auto sNumber: tmp) {
                curr[left] = sNumber.first;
                curr[right] = sNumber.second;
                dfs(res, curr, left + 1, right - 1);
            }
            if (left != 0) {
                curr[left] = '0';
                curr[right] = '0';
                dfs(res, curr, left + 1, right - 1);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
