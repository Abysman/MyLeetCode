//
//  main.cpp
//  739.Daily Temperatures
//
//  Created by Abysman on 2019/1/1.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int s = T.size(), j;
        vector<int> res(s);
        for (int i = s - 1; i >= 0; --i) {
            j = i + 1;
            while (j < s && T[i] >= T[j]) {
                if (res[j] > 0) j = j + res[j];
                else j = s;
            }
            if (j < s) res[i] = j - i;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> record;
        vector<int> res(T.size());
        int s = T.size();
        record.push(0);
        for (int i = 1; i < s; ++i) {
            while (!record.empty() && T[i] > T[record.top()]) {
                res[record.top()] = i - record.top();
                record.pop();
            }
            record.push(i);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
