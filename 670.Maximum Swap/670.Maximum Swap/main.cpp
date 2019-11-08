//
//  main.cpp
//  670.Maximum Swap
//
//  Created by stevenxu on 11/8/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:

    int maximumSwap(int num) {
        string numstr = std::to_string(num);

        int maxidx = -1; int maxdigit = -1;
        int leftidx = -1; int rightidx = -1;

        for (int i = numstr.size() - 1; i >= 0; --i) {
            // current digit is the largest by far
            if (numstr[i] > maxdigit) {
                maxdigit = numstr[i];
                maxidx = i;
                continue;
            }

            // best candidate for max swap if there is no more
            // such situation on the left side
            if (numstr[i] < maxdigit) {
                leftidx = i;
                rightidx = maxidx;
            }
        }

        // num is already in order
        if (leftidx == -1) return num;

        std::swap(numstr[leftidx], numstr[rightidx]);

        return std::stoi(numstr);
    }
};



class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> record(s.size());
        record[s.size() - 1] = s.size() - 1;
        for (int i = s.size() - 2; i >= 0; --i) {
            if (s[i] > s[record[i + 1]]) record[i] = i;
            else record[i] = record[i + 1];
        }
        for (int i = 0; i < s.size() - 1; ++i) {
            if (record[i] != i && s[record[i]] != s[i]) {
                swap(s[i], s[record[i]]);
                break;
            }
        }
        return stoi(s);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
