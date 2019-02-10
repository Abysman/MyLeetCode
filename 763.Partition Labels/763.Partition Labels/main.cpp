//
//  main.cpp
//  763.Partition Labels
//
//  Created by Abysman on 2019/2/9.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> chars(26, 0), res;
        int lastIndex = 0, maxIndex = -1;
        for (int i = 0; i < S.size(); ++i) {
            chars[S[i] - 'a'] = i;
        }
        for (int i = 0; i < S.size(); ++i) {
            maxIndex = max(maxIndex, chars[S[i] - 'a']);
            if (i == maxIndex) {
                res.push_back(i - lastIndex + 1);
                lastIndex = i + 1;
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
