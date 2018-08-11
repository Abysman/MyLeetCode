//
//  main.cpp
//  22.Generate Parentheses
//
//  Created by Abysman on 2018/8/11.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<string> generateParenthesis(int n) {
//        vector<string> res;
//        addingpar(res, "", n, 0);
//        return res;
//    }
//    void addingpar(vector<string> &v, string str, int n, int m){
//        if(n==0 && m==0) {
//            cout << str << "\n";
//            v.push_back(str);
//            return;
//        }
//        if(m > 0){ addingpar(v, str+")", n, m-1); }
//        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
//    }
//};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution sol = Solution();
    vector<string> res = sol.generateParenthesis(3);
    return 0;
}
