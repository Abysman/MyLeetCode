//
//  main.cpp
//  1243.Array Transformation
//
//  Created by stevenxu on 11/2/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;;
class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        vector<int> res = arr;
        while (true) {
            for (int i = 1; i < arr.size() - 1; ++i) {
                if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) res[i] = arr[i] - 1;
                if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1]) res[i] = arr[i] + 1;
            }
            if (arr == res) break;
            arr = res;
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    Solution s = Solution();
    vector<int> test = {2,1,2,1,1,2,2,1};
    s.transformArray(test);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
