//
//  main.cpp
//  771.Jewels and Stones
//
//  Created by Abysman on 2018/10/6.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>

//int numJewelsInStones(string J, string S) {
//    int res = 0;
//    unordered_set<char> setJ(J.begin(), J.end());
//    for (char s : S) if (setJ.count(s)) res++;
//    return res;
//}

class Solution {
public:
    int numJewelsInStones(std::string J, std::string S) {
        int res = 0;
        for (int i = 0; i < S.length(); ++i) {
            char curr = S[i];
            for (int j = 0; j < J.length(); ++j) {
                if (J[j] == curr) {
                    res++;
                    break;
                }
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
