//
//  main.cpp
//  658.Find K Closest Elements
//
//  Created by Abysman on 2019/2/5.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0, high = arr.size() - k;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (x - arr[mid] > arr[mid + k] - x) low = mid + 1;
            else high = mid;
        }
        return vector<int> (arr.begin() + low, arr.begin() + low + k);
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
