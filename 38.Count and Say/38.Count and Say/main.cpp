//
//  main.cpp
//  38.Count and Say
//
//  Created by Abysman on 2018/8/17.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//string countAndSay(int n) {
//    if (n == 0) return "";
//    string res = "1";
//    while (--n) {
//        string cur = "";
//        for (int i = 0; i < res.size(); i++) {
//            int count = 1;
//            while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
//                count++;
//                i++;
//            }
//            cur += to_string(count) + res[i];
//        }
//        res = cur;
//    }
//    return res;
//}

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        string next = "";
        char count = '0';
        char tmp = '1';
        for (int i = 1; i < n; i++) {
            string::reverse_iterator iter;
            next = "";
            for (iter = res.rbegin(); iter < res.rend(); ++iter) {
                if (*iter == tmp) {
                    count = (count - '0' + 1) + '0';
                }
                else if (*iter != tmp){
                    next = next + tmp;
                    next = next + count;
                    tmp = *iter;
                    count = '1';
                }
            }
            next = next + tmp;
            next = next + count;
            reverse(next.begin(), next.end());
            res = next;
            tmp = '1';
            count = '0';
        }

        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol = Solution();
    cout << sol.countAndSay(4);
    return 0;
}
