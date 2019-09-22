//
//  main.cpp
//  1197.Minimum Knight Moves
//
//  Created by stevenxu on 9/22/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int minKnightMoves(int x, int y) {
        if(x == 0 && y == 0)
            return 0;
        vector<pair<int, int>> dirs = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1},
                                       {-2, 1}, {-1, 2}};
        unordered_map<int, unordered_map<int, bool>> visited;
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        pair<int, int> curr;
        int moves = 0;
        while (!q.empty()) {
            int n = q.size();
            moves += 1;
            for (int i = 0; i < n; ++i) {
                curr = q.front();
                q.pop();
                for (auto dir: dirs) {
                    int nextX = dir.first + curr.first;
                    int nextY = dir.second + curr.second;
                    if (nextX == x && nextY == y) return moves;
                    if (!visited[nextX][nextY] && nextX * x >= 0 && nextY * y >= 0) {
                        q.push({nextX, nextY});
                        visited[nextX][nextY] = true;
                    }
                }
            }
            
        }
        return moves;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
