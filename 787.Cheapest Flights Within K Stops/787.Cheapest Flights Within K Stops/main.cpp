//
//  main.cpp
//  787.Cheapest Flights Within K Stops
//
//  Created by Abysman on 2019/2/8.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> res(n, 1e8);
        res[src] = 0;
        for (int i = 0; i < K + 1; ++i) {
            vector<int> tmp(res);
            for (auto f: flights) {
                tmp[f[1]] = min(tmp[f[1]], res[f[0]] + f[2]);
            }
            res = tmp;
        }
        return res[dst] == 1e8 ? -1 : res[dst];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
