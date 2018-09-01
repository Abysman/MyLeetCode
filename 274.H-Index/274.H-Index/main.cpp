//
//  main.cpp
//  274.H-Index
//
//  Created by Abysman on 2018/8/31.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int hIndex(vector<int>& citations) {
//        sort(citations.begin(), citations.end());
//        for (int j = 0; j < citations.size(); ++j) {
//            if (citations[j] >= citations.size() - j) {
//                return citations.size() - j;
//            }
//        }
//        return 0;
//    }
//};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        if (citations.size() == 1) {
            return citations[0] == 0 ? 0 : 1;
        };
        sort(citations.begin(), citations.end());
        int h = INT_MIN;
        if (citations[citations.size() - 1] == 0) h = 0;
        if (citations[0] >= citations.size()) h = citations.size();
        else {
            for (int j = 0; j < citations.size(); ++j) {
                int tmp = citations.size() - j;
                if (citations[tmp - 1] <= j && citations[tmp] >= j) {
                    if (j > h) h = j;
                }
            }
        }
        return h;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
