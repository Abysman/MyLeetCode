//
//  main.cpp
//  1102.Path With Maximum Minimum Value
//
//  Created by stevenxu on 12/31/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;;

class Solution {
    vector<int> dirs = {0, -1, 0, 1, 0};
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        priority_queue<pair<int, pair<int, int>>> pq;
        int r = A.size(), c = A[0].size();
        int res = A[0][0];
        pq.push({A[0][0], {0, 0}});
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int currV = curr.first, currX = curr.second.first, currY = curr.second.second;
            res = min(res, currV);
            if (currX == r - 1 && currY == c - 1) return res;
            for (int i = 0; i < 4; ++i) {
                int nextX = currX + dirs[i], nextY = currY + dirs[i + 1];
                if (nextX >= 0 && nextX < r && nextY >= 0 && nextY < c && A[nextX][nextY] >= 0) {
                    pq.push({A[nextX][nextY], {nextX, nextY}});
                    A[nextX][nextY] = -1;
                }
            }
        }
        return -1;
    }
};
int main(int argc, const char * argv[]) {
    tuple<int, int, int> t = {1,2,3};
    pair<int, int> c = {1,2};
    cout << get<1>(c) << " " << "\n";
    cout << get<1>(t) << "\n";
//    int b = (int)v.size();
//    cout << b << "\n";
    return 0;
}
