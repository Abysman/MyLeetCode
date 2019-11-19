//
//  main.cpp
//  324.Wiggle Sort II
//
//  Created by stevenxu on 11/18/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
private:
    int index(int i, int n) {
        return (2 * i + 1 ) % (n | 1);
    }
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (nums[index(j, n)] > mid) swap(nums[index(j++, n)], nums[index(i++, n)]);
            else if (nums[index(j, n)] < mid) swap(nums[index(j, n)], nums[index(k--, n)]);
            else j++;
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
