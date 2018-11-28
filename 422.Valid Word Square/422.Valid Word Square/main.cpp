//
//  main.cpp
//  422.Valid Word Square
//
//  Created by Abysman on 2018/11/28.
//  Copyright © 2018 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                if (j >= words.size() || i >= words[j].size() || words[i][j] != words[j][i])  {
                    return false;
                }
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
