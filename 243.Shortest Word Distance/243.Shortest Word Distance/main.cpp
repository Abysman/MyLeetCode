//
//  main.cpp
//  243.Shortest Word Distance
//
//  Created by Abysman on 2018/11/25.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int res = INT_MAX;
        int index1 = -1;
        int index2 = -1;
        for (int i = 0; i < n; ++i) {
            if (words[i].compare(word1) == 0) index1 = i;
            else if (words[i].compare(word2) == 0) index2 = i;
            if (index1 >= 0 && index2 >= 0 && abs(index1 - index2) < res)
                res = abs(index1 - index2);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
