//
//  main.cpp
//  520.Detect Capital
//
//  Created by stevenxu on 11/23/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) return true;
        int count1 = 0, count2 = 0;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                count1++;
            } else if (i > 0 && word[i] >= 'a' && word[i] <= 'z') {
                count2++;
            }
        }
        return count1 == word.size() || count2 == word.size() - 1;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
