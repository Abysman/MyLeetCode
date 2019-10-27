//
//  main.cpp
//  975.Odd Even Jump
//
//  Created by stevenxu on 10/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size(), res = 1;
        vector<pair<int, int>> tmp(n);
        tmp[n - 1] = {1, 1};
        map<int, int> record;
        record[A[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            auto hi = record.lower_bound(A[i]), low = record.upper_bound(A[i]);
            if (hi != record.end()) tmp[i].first = tmp[hi->second].second;
            if (low != record.begin()) tmp[i].second = tmp[(--low)->second].first;
            if (tmp[i].first) res++;
            record[A[i]] = i;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
