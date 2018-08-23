//
//  main.cpp
//  80.Remove Duplicates from Sorted Array II
//
//  Created by Abysman on 2018/8/23.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//int removeDuplicates(vector<int>& nums) {
//    int i = 0;
//    for (int n : nums)
//        if (i < 2 || n > nums[i-2])
//            nums[i++] = n;
//    return i;
//}


//  mine
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int curr = nums[0];
        int count = 0, tmp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (curr == nums[i]) {
                tmp += 1;
                if (tmp > 2) {
                    count += 1;
                }
            }
            else {
                curr = nums[i];
                tmp = 1;
            }
            nums[i - count] = nums[i];
        }
        return nums.size() - count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
