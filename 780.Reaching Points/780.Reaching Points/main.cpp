//
//  main.cpp
//  780.Reaching Points
//
//  Created by Abysman on 2019/1/1.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx > ty) {
                if (ty == sy) return (tx - sx) % sy == 0;
                tx %= ty;
            } else {
                if (tx == sx) return (ty - sy) % sx == 0;
                ty %= tx;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (tx < sx || ty < sy) {
            return false;
        }
        if (tx == sx && ty == sy) {
            return true;
        }
        if (tx == sx) {
            return (ty - sy) % tx == 0;
        }
        if (ty == sy) {
            return (tx - sx) % ty == 0;
        }
        
        if (tx > ty) {
            return reachingPoints(sx, sy, tx % ty, ty);
        }
        return reachingPoints(sx, sy, tx, ty % tx);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s = Solution();

    std::cout << s.reachingPoints(9, 10, 9, 19);
    return 0;
}
