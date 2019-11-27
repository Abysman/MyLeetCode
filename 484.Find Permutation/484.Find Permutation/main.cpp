//
//  main.cpp
//  484.Find Permutation
//
//  Created by stevenxu on 11/27/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> res(s.size() + 1);
        s += "I";
        int last = -1, curr = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != 'I') continue;
            if (last + 1 == i) {
                res[++last] = curr++;
            } else {
                for (int j = i; j > last; --j) {
                    res[j] = curr++;
                }
                last = i;
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
