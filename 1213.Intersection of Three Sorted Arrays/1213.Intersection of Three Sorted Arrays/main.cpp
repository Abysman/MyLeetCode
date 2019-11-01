//
//  main.cpp
//  1213.Intersection of Three Sorted Arrays
//
//  Created by stevenxu on 11/1/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
        int i = 0, j = 0, k = 0;
        vector<int> res;
        while (i < n1 && j < n2 && k < n3) {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                res.push_back(arr1[i]);
                i++;j++;k++;
                continue;
            } else {
                int currMin = min(arr1[i], min(arr2[j], arr3[k]));
                if (currMin == arr1[i]) i++;
                if (currMin == arr2[j]) j++;
                if (currMin == arr3[k]) k++;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
