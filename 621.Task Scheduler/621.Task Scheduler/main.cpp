//
//  main.cpp
//  621.Task Scheduler
//
//  Created by Abysman on 2019/1/9.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count = 0;
        map<char, int> record;
        for (auto c:tasks) {
            record[c] += 1;
            count = max(count, record[c]);
        }
        int res = (n + 1) * (count - 1);
        for (auto r:record) {
            if (r.second == count) res++;
        }
        return max((int)tasks.size(), res);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
