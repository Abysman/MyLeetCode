//
//  main.cpp
//  815.Bus Routes
//
//  Created by stevenxu on 9/23/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
    int res = INT_MAX;
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int, vector<int>> stopToBus;
        for (int i = 0; i < routes.size(); ++i) {
            vector<int> route = routes[i];
            for (int j = 0; j < route.size(); ++j) {
                stopToBus[route[j]].push_back(i);
            }
        }
        queue<pair<int, int>> q;
        unordered_set<int> seenStop = {S};
        q.push({S, 0});
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            if (curr.first == T) return curr.second;
            for (int bus: stopToBus[curr.first]) {
                for (int stop: routes[bus]) {
                    if (seenStop.find(stop) == seenStop.end()) {
                        seenStop.insert(stop);
                        q.push({stop, curr.second + 1});
                    }
                }
                routes[bus].clear();
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
