//
//  main.cpp
//  85.Maximal Rectangle
//
//  Created by stevenxu on 12/28/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n), left(n), right(n, n - 1);
        int res = 0;
        for (int i = 0; i < m; ++i) {
            int lb = 0;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], lb);
                } else {
                    lb = j + 1;
                    left[j] = 0;
                }
            }
            int rb = n - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], rb);
                    heights[j]++;
                    res = max(res, (right[j] - left[j] + 1) * heights[j]);
                } else {
                    rb = j - 1;
                    right[j] = n - 1;
                    heights[j] = 0;
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
