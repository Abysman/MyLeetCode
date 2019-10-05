//
//  main.cpp
//  443.String Compression
//
//  Created by stevenxu on 10/5/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() <= 1) return chars.size();
        int i = 0, j = 0;
        while (i < chars.size()) {
            chars[j] = chars[i];
            int count = 0;
            while (i < chars.size() && chars[i] == chars[j]) {
                count++;
                i++;
            }
            if (count == 1) {
                j++;
            } else {
                string str = to_string(count);
                for (auto c: str) {
                    chars[++j] = c;
                }
                j++;
            }
        }
        return j;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
