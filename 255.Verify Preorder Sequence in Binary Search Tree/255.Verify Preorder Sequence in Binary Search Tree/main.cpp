//
//  main.cpp
//  255.Verify Preorder Sequence in Binary Search Tree
//
//  Created by stevenxu on 7/27/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;
        int min_value = INT_MIN;
        for (int i = 0; i < preorder.size(); ++i) {
            if (s.empty() || preorder[i] < preorder[i - 1]) {
                if (preorder[i] <= min_value) return false;
                s.push(preorder[i]);
            } else {
                while (!s.empty() && s.top() < preorder[i]) {
                    min_value = s.top();
                    s.pop();
                }
                s.push(preorder[i]);
            }
        }
        return true;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
