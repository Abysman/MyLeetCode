//
//  main.cpp
//  417.Pacific Atlantic Water Flow
//
//  Created by stevenxu on 12/28/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;;
class Solution {
    vector<int> dirs = {0, -1, 0, 1, 0};
    vector<vector<int>> res;
    vector<vector<int>> visited;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        visited.resize(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            helper(matrix, i, 0, INT_MIN, 1);
            helper(matrix, i, n - 1, INT_MIN, 2);
        }
        for (int j = 0; j < n; ++j) {
            helper(matrix, 0, j, INT_MIN, 1);
            helper(matrix, m - 1, j, INT_MIN, 2);
        }
        return res;
    }
    
    void helper(vector<vector<int>>& matrix, int i, int j, int pre, int preV) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] < pre || (visited[i][j] & preV) == preV)
            return;
        visited[i][j] |= preV;
        if (visited[i][j] == 3) res.push_back({i, j});
        for (int k = 0; k < 4; ++k) {
            int nextI = i + dirs[k], nextJ = j + dirs[k + 1];
            helper(matrix, nextI, nextJ, matrix[i][j], visited[i][j]);
        }
    }
};
class Solution {
    vector<int> dirs = {0, -1, 0, 1, 0};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            helper(matrix, i, 0, pacific);
            helper(matrix, i, n - 1, atlantic);
        }
        for (int j = 0; j < n; ++j) {
            helper(matrix, 0, j, pacific);
            helper(matrix, m - 1, j, atlantic);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
    
    void helper(vector<vector<int>>& matrix, int i, int j, vector<vector<bool>> &visited) {
        int m = matrix.size(), n = matrix[0].size();
        visited[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int nextI = i + dirs[k], nextJ = j + dirs[k + 1];
            if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n || visited[nextI][nextJ] || matrix[nextI][nextJ] < matrix[i][j]) continue;
            helper(matrix, nextI, nextJ, visited);
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> test = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};

//    vector<vector<int>> test = {{1,2,3},{8,9,4},{7,6,5}};
    Solution s = Solution();
    vector<vector<int>> res = s.pacificAtlantic(test);
    std::cout << "Hello, World!\n";
    return 0;
}
