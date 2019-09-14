//
//  main.cpp
//  349.Intersection of Two Arrays
//
//  Created by stevenxu on 9/14/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()){
            return std::vector<int>();
        }
        std::unordered_set<int> set{nums1.cbegin(), nums1.cend()};
        std::vector<int> intersections;
        for (auto n: nums2){
            if (set.erase(n) > 0){ // if n exists in set, then 1 is returned and n is erased; otherwise, 0.
                intersections.push_back(n);
            }
        }
        return intersections;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
