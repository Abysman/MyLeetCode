//
//  main.cpp
//  743.Network Delay Time
//
//  Created by stevenxu on 9/25/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

//  Bellman Ford
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> delays(N + 1, INT_MAX);
        delays[K] = 0;
        for (int i = 0; i < N - 1; ++i) {
            for (vector<int> time: times) {
                int u = time[0], v = time[1], w = time[2];
                if (delays[u] != INT_MAX && delays[u] + w < delays[v]) {
                    delays[v] = delays[u] + w;
                }
            }
        }
        int res = 0;
        for (int i = 1; i < N + 1; ++i) {
            if (delays[i] > res) res = delays[i];
            // res = max(res, delays[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};

//  Dijkstra
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> record(N + 1);
        for (vector<int> time: times) {
            record[time[0]].push_back({time[1], time[2]});
        }
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(N + 1, false);
        pq.push({0, K});
        int u, v, w;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            u = p.second;
            if (visited[u]) continue;
            for (auto &to: record[u]) {
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
            visited[u] = true;
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
