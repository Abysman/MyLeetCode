//
//  main.cpp
//  59.Spiral Matrix II
//
//  Created by Abysman on 2018/10/30.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<vector<int> > generateMatrix(int n) {
//        vector<vector<int> > ret( n, vector<int>(n) );
//        int k = 1, i = 0;
//        while( k <= n * n )
//        {
//            int j = i;
//            // four steps
//            while( j < n - i )             // 1. horizonal, left to right
//                ret[i][j++] = k++;
//            j = i + 1;
//            while( j < n - i )             // 2. vertical, top to bottom
//                ret[j++][n-i-1] = k++;
//            j = n - i - 2;
//            while( j > i )                  // 3. horizonal, right to left
//                ret[n-i-1][j--] = k++;
//            j = n - i - 1;
//            while( j > i )                  // 4. vertical, bottom to  top
//                ret[j--][i] = k++;
//            i++;      // next loop
//        }
//        return ret;
//    }
//};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> tmp(n, 0);
        vector<vector<int>> res(n, tmp);
        int count = 0;
        int last;
        res[n/2][n/2] = n * n;
        while (n > 0) {
            if (count == 0) last = 1;
            else last = res[count][count - 1] + 1;
            helper(res, count, count, n, last);
            n = n - 2;
            count++;
        }
        return res;
    }
    
    void helper(vector<vector<int>>& res, int r, int c, int n, int offset) {
        for (int i = 0; i < n - 1; ++i) {
            res[r][c + i] = i + offset;
        }
        for (int i = 0; i < n - 1; ++i) {
            res[r + i][c + n - 1] = i + offset + n - 1;
        }
        for (int i = n - 1; i > 0; --i) {
            res[r + n - 1][c + i] = offset + 3 * (n - 1) - i;
        }
        for (int i = n - 1; i > 0; --i) {
            res[r + i][c] = offset + 4 * (n - 1) - i;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s = Solution();
    s.generateMatrix(5);
    std::cout << "Hello, World!\n";
    return 0;
}
