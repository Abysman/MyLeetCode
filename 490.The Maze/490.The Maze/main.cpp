//
//  main.cpp
//  490.The Maze
//
//  Created by Abysman on 2019/2/14.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.empty()) return true;
        int row = maze.size(), col = maze[0].size();
        if (row == 1 && col == 1) return true;
        set<vector<int>> visited;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        queue<vector<int>> record;
        
        record.push(start);
        visited.insert(start);
        
        while (!record.empty()) {
            vector<int> curr = record.front();
            record.pop();
            
            for (int i = 0; i < 4; ++i) {
                vector<int> newP = curr;
                
                
                while (maze[newP[0]][newP[1]] != 1) {
                    int nextX = newP[0] + dir[i][0];
                    int nextY = newP[1] + dir[i][1];
                    if (nextX >= 0 && nextX <= row - 1 && nextY >= 0 && nextY <= col - 1
                        && (maze[nextX][nextY] == 0)) {
                        newP[0] = nextX;
                        newP[1] = nextY;
                    } else break;
                }
                if (newP[0] == destination[0] && newP[1] == destination[1]) return true;
                if (visited.find(newP) == visited.end()) {
                    visited.insert(newP);
                    record.push(newP);
                }
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> start = {0,1};
    vector<int> end = {0,3};
    vector<vector<int>> test = {{0,0,1,0,0}};
    Solution s = Solution();
    cout << s.hasPath(test, start, end);
    return 0;
}
