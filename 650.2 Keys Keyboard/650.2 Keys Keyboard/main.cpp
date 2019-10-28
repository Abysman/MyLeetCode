//
//  main.cpp
//  650.2 Keys Keyboard
//
//  Created by stevenxu on 10/12/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;;
//class Solution {
//public:
//    int minSteps(int n) {
//        if (n == 1) return 0;
//        for (int i = 2; i < n; i++)
//            if (n % i == 0) return i + minSteps(n / i);
//        return n;
//    }
//};

class Solution {
    vector<vector<int>> dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> res;
        int numQueens = queens.size();
        unordered_set<pair<int, int>> queenSet;
        for (auto queen: queens) {
            queenSet.insert({queen[0], queen[1]});
        }
        queue<pair<int, pair<int, int>>> position;
        
        for (int i = 0; i < dirs.size(); ++i) {
            position.push({i, {king[0], king[1]}});
        }
        while (!position.empty()) {
            int dir = position.front().first;
            auto curr = position.front().second;
            position.pop();
            if (curr.first >= 0 && curr.first <= 8 && curr.second >= 0 && curr.second <= 8) {
                int nextX = curr.first + dirs[dir][0], nextY = curr.second + dirs[dir][1];
                if (queenSet.find({nextX, nextY}) != queenSet.end()) {
                    vector<int> q = {nextX, nextY};
                    res.push_back(q);
                }
                position.push({dir, {nextX, nextY}});
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
