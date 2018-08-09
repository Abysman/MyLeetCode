//
//  main.cpp
//  167.Two Sum II - Input array is sorted
//
//  Created by Abysman on 2018/8/9.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j){
            if (numbers[i] + numbers[j] == target) {
                break;
            }
            else if (numbers[i] + numbers[j] > target) {
                j--;
            }
            else if (numbers[i] + numbers[j] < target) {
                i++;
            }
        }
        vector<int> res = {i+1, j+1};
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol = Solution();
    vector<int> a = {2,7,11,15};
    vector<int> res = sol.twoSum(a, 9);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << "\n";
    }
    std::cout << "Hello, World!\n";
    return 0;
}
