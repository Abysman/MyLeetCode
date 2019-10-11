//
//  main.cpp
//  1042.Flower Planting With No Adjacent
//
//  Created by stevenxu on 10/10/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> res(N);
        vector<vector<int>> neighbrs(N + 1);
        for (auto path: paths) {
            neighbrs[path[0]].push_back(path[1]);
            neighbrs[path[1]].push_back(path[0]);
        }
        res[0] = 1;
        for (int i = 2; i < N + 1; ++i) {
            unordered_set<int> colorsUsed;
            for (int neighbr: neighbrs[i]) colorsUsed.insert(res[neighbr - 1]);
            for (int j = 1; j < 5; ++j) {
                if (colorsUsed.find(j) == colorsUsed.end()) {
                    res[i - 1] = j;
                    break;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
