//
//  main.cpp
//  77.Combinations
//
//  Created by Abysman on 2018/7/20.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> combine;
        subcombine(n, k, 1, res, combine);
        return res;
    }
    
    void subcombine(int n, int k, int begin, vector<vector<int>>& res, vector<int> combine) {
        if (combine.size() == k) {
            res.push_back(combine);
            return;
        }
        for (int i = begin; i < n + 1; ++i) {
            if (find(combine.begin(), combine.end(), i) == combine.end()) combine.push_back(i);
            else continue;
            subcombine(n, k, i + 1, res, combine);
            combine.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
