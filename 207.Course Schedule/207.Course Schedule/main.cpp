//
//  main.cpp
//  207.Course Schedule
//
//  Created by Abysman on 2018/9/16.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses);
        queue<int> q;
        int count = 0;
        for (auto p: prerequisites) {
            indegrees[p.first] += 1;
            adj[p.second].push_back(p.first);
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;
            for (auto neighbr: adj[curr]) {
                indegrees[neighbr]--;
                if (indegrees[neighbr] == 0) q.push(neighbr);
            }
        }
        return count == numCourses;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
