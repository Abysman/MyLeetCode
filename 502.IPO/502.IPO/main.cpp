//
//  main.cpp
//  502.IPO
//
//  Created by stevenxu on 10/24/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int> low;
        multiset<pair<int, int>> high;
        for (int i = 0; i < Profits.size(); ++i) {
            if(Profits[i] > 0) if (Capital[i] <= W) low.push(Profits[i]); else high.emplace(Capital[i], Profits[i]);
        }
        while (k-- && !low.empty()) {
            W += low.top();
            low.pop();
            for (auto iter = high.begin(); high.size() && iter->first <= W; iter = high.erase(iter)) low.push(iter->second);
        }
        return W;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
