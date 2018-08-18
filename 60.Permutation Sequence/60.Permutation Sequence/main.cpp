//
//  main.cpp
//  60.Permutation Sequence
//
//  Created by Abysman on 2018/8/18.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            tmp.push_back(i + 1);
        }
        for (int i = 0; i < k - 1; ++i) {
            int j, h;
            for (j = n - 2; j >= 0; j--) {
                if (tmp[j] < tmp[j + 1]) break;
            }
            if (j < 0) reverse(tmp.begin(), tmp.end());
            else {
                for (h = n - 1; h > j; h--) {
                    if (tmp[h] > tmp[j]) break;
                }
                swap(tmp[h], tmp[j]);
                reverse(tmp.begin() + j + 1, tmp.end());
            }
            string res = "";
        }
        string res = "";
        for (int i = 0; i < tmp.size(); ++i) {
            res = res + to_string(tmp[i]);
        }
        return res;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
