//
//  main.cpp
//  74.Search a 2D Matrix
//
//  Created by Abysman on 2018/8/9.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


//  binary search
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int> > &matrix, int target) {
//        int n = matrix.size();
//        int m = matrix[0].size();
//        int l = 0, r = m * n - 1;
//        while (l != r){
//            int mid = (l + r - 1) >> 1;
//            if (matrix[mid / m][mid % m] < target)
//                l = mid + 1;
//            else
//                r = mid;
//        }
//        return matrix[r / m][r % m] == target;
//    }
//};

//  mine
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = 0;
        while (i < matrix.size() && j < matrix[0].size()) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) return false;
            if ((i+1) < matrix.size() && matrix[i + 1][j] <= target) {
                i++;
            }
            else if ((j+1) < matrix[0].size() && matrix[i][j + 1] <= target) {
                j++;
            }
            else return false;
        }
        return false;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a = {{1,1}};
    Solution sol = Solution();
    sol.searchMatrix(a, 2);
    return 0;
}
