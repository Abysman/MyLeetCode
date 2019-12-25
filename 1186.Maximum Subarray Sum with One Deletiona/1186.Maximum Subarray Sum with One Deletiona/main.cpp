//
//  main.cpp
//  1186.Maximum Subarray Sum with One Deletiona
//
//  Created by stevenxu on 12/25/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> f(n), b(n);
        int res = 0, sum, overall_max;
        sum = overall_max = f[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            sum = max(arr[i], sum + arr[i]);
            overall_max = max(overall_max, sum);
            f[i] = sum;
        }
        overall_max = b[n - 1] = sum = arr[n - 1];
        for (int i = arr.size() - 2; i >= 0; --i) {
            sum = max(arr[i], sum + arr[i]);
            overall_max = max(overall_max, sum);
            b[i] = sum;
        }
        res = overall_max;
        for(int i = 1; i < n - 1; i++) {
            res = max(res, f[i - 1] + b[i + 1]);
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
