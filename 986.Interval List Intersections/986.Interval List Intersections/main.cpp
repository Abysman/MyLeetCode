//
//  main.cpp
//  986.Interval List Intersections
//
//  Created by stevenxu on 9/14/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

//  https://leetcode.com/problems/interval-list-intersections/discuss/334206/C%2B%2B-Concise-Two-Pointers
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        for(int i = 0, j = 0; i < A.size() && j < B.size();) {
            int lo = max(A[i][0], B[j][0]), hi = min(A[i][1], B[j][1]);
            if(lo <= hi) res.push_back({lo, hi});
            if(hi == A[i][1]) i++;
            else j++;
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int num1 = A.size(), num2 = B.size();
        int i = 0, j = 0;
        while (i < num1 && j < num2) {
            vector<int> currA = A[i], currB = B[j];
            if (currA[1] < currB[0]) {
                i++;
            }
            else if (currA[0] > currB[1]) {
                j++;
            }
            else {
                vector<int> curr(2);
                curr[0] = max(currA[0], currB[0]);
                curr[1] = min(currA[1], currB[1]);
                res.push_back(curr);
                if (currA[1] < currB[1]) i++;
                else if (currA[1] > currB[1]) j++;
                else if (currA[1] == currB[1]) {
                    i++;
                    j++;
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
