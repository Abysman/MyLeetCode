//
//  main.cpp
//  305.Number of Islands II
//
//  Created by stevenxu on 9/13/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;;
class Solution {
    unordered_map<int, int> map;
    int count = 0;
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<int> res;
        for (auto position: positions) {
            int currIndex = n * position[0] + position[1];
            if (map.find(currIndex) != map.end()) {
                res.push_back(count);
                continue;
            }
            bool newIsland = true;
            unordered_map<int, vector<int>> tmp;
            for (auto dir: dirs) {
                int nextX = position[0] + dir.first, nextY = position[1] + dir.second;
                if (nextX < 0 || nextX > m - 1 || nextY < 0 || nextY > n - 1) continue;
                int nextIndex = n * nextX + nextY;
                if (map.find(nextIndex) != map.end()) {
                    newIsland = false;
                    uni(currIndex, nextIndex);
                }
            }
            if (newIsland) {
                count++;
                map[currIndex] = currIndex;
            }
            res.push_back(count);
        }
        return res;
    }

    int find(int n) {
        if (!map.count(n)) {
            map[n] = n;
            count++;
        }
        if (map[n] != n) {
            map[n] = find(map[n]);
        }
        return map[n];
    }

    void uni(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            map[a] = b;
            count--;
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s = Solution();
    vector<vector<int>> tests = {{2,2},{2,1},{1,3},{0,4}};
    s.numIslands2(3, 6, tests);
    return 0;
}
