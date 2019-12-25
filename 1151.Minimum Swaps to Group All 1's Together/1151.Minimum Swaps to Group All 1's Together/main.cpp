//
//  main.cpp
//  1151.Minimum Swaps to Group All 1's Together
//
//  Created by stevenxu on 12/25/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int count = 0, currZeros = 0, res = INT_MAX;
        for (int num: data) {
            if (num == 1) count++;
        }
        if (count == 1) return 0;
        int left = 0, right = 0;
        for (;right < count; ++right) {
            if (data[right] == 0) currZeros++;
        }
        right--;
        while (right < data.size()) {
            res = min(res, currZeros);
            if (right == data.size() - 1) break;
            currZeros -= data[left] == 0 ? 1 : 0;
            left++; right++;
            currZeros += data[right] == 0 ? 1 : 0;
        }
        return res == INT_MAX ? 0 : res;
    }
};
class Solution {
public:
    int minSwaps(vector<int>& data) {
        for(int i = 1; i < data.size(); ++i) {
            data[i] += data[i-1];
        }
        int K = data.back();
        if(K == 0)
            return 0;
        int max_one = data[K-1];
        for(int i = K; i < data.size(); ++i) {
            max_one = max(max_one, data[i] - data[i-K]);
        }
        return K - max_one;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
