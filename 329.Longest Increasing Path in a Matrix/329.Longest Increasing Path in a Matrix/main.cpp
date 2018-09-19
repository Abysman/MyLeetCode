//
//  main.cpp
//  329.Longest Increasing Path in a Matrix
//
//  Created by Abysman on 2018/9/19.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int longestIncreasingPath(vector<vector<int>>& matrix) {
//        int rows = matrix.size();
//        if (!rows) return 0;
//        int cols = matrix[0].size();
//
//        vector<vector<int>> dp(rows, vector<int>(cols, 0));
//        std::function<int(int, int)> dfs = [&] (int x, int y) {
//            if (dp[x][y]) return dp[x][y];
//            vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
//            for (auto &dir : dirs) {
//                int xx = x + dir[0], yy = y + dir[1];
//                if (xx < 0 || xx >= rows || yy < 0 || yy >= cols) continue;
//                if (matrix[xx][yy] <= matrix[x][y]) continue;
//                dp[x][y] = std::max(dp[x][y], dfs(xx, yy));
//            }
//            return ++dp[x][y];
//        };
//        
//        int ret = 0;
//        for (int i = 0; i < rows; ++i) {
//            for (int j = 0; j < cols; ++j) {
//                ret = std::max(ret, dfs(i, j));
//            }
//        }
//
//        return ret;
//    }
//};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int res = 0;
        vector<int> visited(int(matrix.size()) * int(matrix[0].size()), -1);
        for (int i = 0; i < int(matrix.size()); ++i) {
            for (int j = 0; j < int(matrix[0].size()); ++j) {
                if (visited[matrix[0].size() * i + j] == -1) {
                    int currPath = helper(matrix, visited, i, j);
                    if (currPath > res) {
                        res = currPath;
                    }
                }
            }
        }
        return res;
    }
    
    int helper(vector<vector<int>>& matrix, vector<int>& visited, int i, int j) {
        if (visited[i * matrix[0].size() + j] > -1) return visited[i * matrix[0].size() + j];
        int path = 1;
        
        if (i >= 1 && matrix[i - 1][j] > matrix[i][j]) {
            int path1 = helper(matrix, visited, i - 1, j) + 1;
            if (path1 > path) path = path1;
        }
        if (j >= 1 && matrix[i][j - 1] > matrix[i][j]) {
            int path2 = helper(matrix, visited, i, j - 1) + 1;
            if (path2 > path) path = path2;
        }
        if (i + 1<= matrix.size() - 1 && matrix[i + 1][j] > matrix[i][j]) {
            int path3 = helper(matrix, visited, i + 1, j) + 1;
            if (path3 > path) path = path3;
        }
        if (j + 1<= matrix[0].size() - 1 && matrix[i][j + 1] > matrix[i][j]) {
            int path4 = helper(matrix, visited, i, j + 1) + 1;
            if (path4 > path) path = path4;
        }
        visited[i * matrix[0].size() + j] = path;
        return path;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a = {{9,9,4},{6,6,8},{2,1,1},{3,3,4},{5,1,2}};
    Solution sol = Solution();
    cout << sol.longestIncreasingPath(a);
    return 0;
}
