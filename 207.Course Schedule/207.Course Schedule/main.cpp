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
        map<int, int> inDegree;
        queue<int> course;
        int count = 0;
        
        for (int i = 0; i < numCourses; ++i) {
            inDegree[i] = 0;
        }
        
        for (int i = 0; i < prerequisites.size(); ++i) {
            inDegree[prerequisites[i].second] += 1;
        }
        
        for (int i = 0; i < inDegree.size(); ++i) {
            if (inDegree[i] == 0) {
                course.push(i);
            }
        }
        
        while (!course.empty()) {
            int curr = course.front();
            // cout << "curr:" << curr << "\n";
            for (int i = 0; i < prerequisites.size(); ++i) {
                if (prerequisites[i].first == curr) {
                    inDegree[prerequisites[i].second]--;
                    // cout << curr << " " << prerequisites[i].second << " " << inDegree[prerequisites[i].second] << "\n";
                    if (inDegree[prerequisites[i].second] == 0) {
                        // cout << prerequisites[i].second << "\n";
                        course.push(prerequisites[i].second);
                    }
                }
            }
            inDegree[curr] = -1;
            course.pop();
            count++;
        }
        
        if (count == numCourses) return true;
        else return false;
        
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
