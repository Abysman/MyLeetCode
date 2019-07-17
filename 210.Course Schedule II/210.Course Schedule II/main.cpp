//
//  main.cpp
//  210.Course Schedule II
//
//  Created by stevenxu on 7/16/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegrees(numCourses, 0);
        vector<int> res;
        for (vector<int> edge: prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            indegrees[edge[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < indegrees.size(); ++i) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            res.push_back(f);
            for (auto neighbr: graph[f]) {
                indegrees[neighbr]--;
                if (indegrees[neighbr] == 0) {
                    q.push(neighbr);
                }
            }
        }
        if (res.size() == numCourses) {
            return res;
        } else {
            return vector<int>();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
