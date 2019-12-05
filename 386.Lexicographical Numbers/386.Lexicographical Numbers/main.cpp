//
//  main.cpp
//  386.Lexicographical Numbers
//
//  Created by stevenxu on 12/4/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int curr = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = curr;
            if (curr * 10 <=n ) {
                curr *= 10;
            } else {
                if (curr >= n) curr /= 10;
                curr += 1;
                while (curr % 10 == 0) curr /= 10;
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
