//
//  main.cpp
//  973.K Closest Points to Origin
//
//  Created by Abysman on 2019/1/24.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](const vector<int>& p1, const vector<int>& p2) {
            return (p1[0] - p2[0])*(p1[0] + p2[0]) < (p2[1] - p1[1])*(p2[1] + p1[1]); });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b){
            return (a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1]);});
        vector<vector<int>> res;
        
        for (int i = 0; i < K && i < (int)points.size(); ++i) {
            res.push_back(points[i]);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
