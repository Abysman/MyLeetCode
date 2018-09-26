//
//  main.cpp
//  228.Summary Ranges
//
//  Created by Abysman on 2018/9/20.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return vector<string> ();
        nums.push_back(INT_MAX);
        vector<string> res;
        string s = "";
        int curr = nums[0];
        int last = curr;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == last + 1) {
                last += 1;
            }
            else {
                if (last - curr == 0) {
                    s = to_string(last);
                }
                else {
                    s = to_string(curr) + "->" + to_string(last);
                }
                curr = nums[i];
                last = curr;
                res.push_back(s);
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
