//
//  main.cpp
//  1300.Sum of Mutated Array Closest to Target
//
//  Created by stevenxu on 12/31/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if (arr[0] * n > target) {
            if (n * (target / n) == target) return target / n;
            else if (abs(n * (target / n) - target) > abs(n * (target / n + 1) - target)) return target / n + 1;
            else return target / n;
        }
        vector<int> preSum = arr;
        for (int i = 0; i < arr.size(); ++i) {
            preSum[i] = i == 0 ? arr[i] : preSum[i - 1] + arr[i];
        }
        int left = arr[0], right = arr[n - 1];
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            auto f = upper_bound(arr.begin(), arr.end(), mid);
            if (f == arr.end()) continue;
            int currSum = preSum[f - arr.begin() - 1] + mid * (arr.end() - f);
            if (currSum == target) {
                return mid;
            } else if (currSum >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int l1 = 0, l2 = 0;
        for (int num: arr) {
            l1 += num > left ? left : num;
            l2 += num > (left - 1) ? left - 1 : num;
        }
        if (abs(l2 - target) <= abs(l1 - target)) return left - 1;
        else return left;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
