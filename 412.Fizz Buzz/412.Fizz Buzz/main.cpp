//
//  main.cpp
//  412.Fizz Buzz
//
//  Created by Abysman on 2019/1/10.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i < n + 1; ++i) {
            string curr = "";
            if (i % 3 == 0) curr += "Fizz";
            if (i % 5 == 0) curr += "Buzz";
            if (curr == "") curr = to_string(i);
            res.push_back(curr);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
