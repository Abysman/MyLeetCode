//
//  main.cpp
//  299.Bulls and Cows
//
//  Created by Abysman on 2018/9/27.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    // only contains digits
//    string getHint(string secret, string guess) {
//        int aCnt = 0;
//        int bCnt = 0;
//        vector<int> sVec(10, 0); // 0 ~ 9 for secret
//        vector<int> gVec(10, 0); // 0 ~ 9 for guess
//        if (secret.size() != guess.size() || secret.empty()) { return "0A0B"; }
//        for (int i = 0; i < secret.size(); ++i) {
//            char c1 = secret[i]; char c2 = guess[i];
//            if (c1 == c2) {
//                ++aCnt;
//            } else {
//                ++sVec[c1-'0'];
//                ++gVec[c2-'0'];
//            }
//        }
//        // count b
//        for (int i = 0; i < sVec.size(); ++i) {
//            bCnt += min(sVec[i], gVec[i]);
//        }
//        return to_string(aCnt) + 'A' + to_string(bCnt) + 'B';
//    }
//};

class Solution {
public:
    string getHint(string secret, string guess) {
        string res = "A";
        unordered_map<char, int> record_A;
        unordered_map<char, int> record_B;
        int count = 0;
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                count += 1;
            }
            else {
                record_A[secret[i]]++;
                record_B[guess[i]]++;
            }
        }
        res = to_string(count) + res;
        count = 0;
        for (auto k = record_A.begin(); k != record_A.end(); ++k) {
            count += min(k->second, record_B[k->first]);
        }
        res = res + to_string(count) + 'B';
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
