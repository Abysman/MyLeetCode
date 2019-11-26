//
//  main.cpp
//  1266.Minimum Time Visiting All Points
//
//  Created by stevenxu on 11/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 1; i < points.size(); i++) {
            ans += max(abs(points[i][1] - points[i - 1][1]), abs(points[i][0] - points[i - 1][0]));
        }
        return ans;
    }
};
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if (points.size() <= 1) return 0;
        int res = 0;
        vector<int> last = points[0];
        for (int i = 1; i < points.size(); ++i) {
            vector<int> curr = points[i];
            int distX = abs(curr[0] - last[0]), distY = abs(curr[1] - last[1]);
            if (distX > distY) {
                res += distY + min(abs(curr[0] - (last[0] + distY)), abs(curr[0] - (last[0] - distY)));
            } else {
                res += distX + min(abs(curr[1] - (last[1] + distX)), abs(curr[1] - (last[1] - distX)));
            }
            last = curr;
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
