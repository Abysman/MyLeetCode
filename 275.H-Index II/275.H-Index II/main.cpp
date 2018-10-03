//
//  main.cpp
//  275.H-Index II
//
//  Created by Abysman on 2018/10/2.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        int l = 0, h = citations.size() - 1;
        int mid = l + (h - l) / 2;
        int n = citations.size();
        while (l <= h) {
            mid = l + (h - l) / 2;
            if (citations[n - mid - 1] > mid) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        return l;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
