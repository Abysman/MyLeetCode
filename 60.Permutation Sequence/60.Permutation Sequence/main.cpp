//
//  main.cpp
//  60.Permutation Sequence
//
//  Created by Abysman on 2018/8/2.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string tmp = "";
        vector<string> record;
        helper(record, tmp, k, n);
        cout << record.size() << "\n";
        return record[record.size() - 1];
    }
    
    int factorial(int n) {
        int result = 1;
        for (int i = 1; i < n + 1; i++) {
            return
        }
    }
    
    void helper(vector<string>& record, string& s, int k, int n) {
        if (s.length() == n) {
            record.push_back(s);
            return;
        }
        for (int i = 1; i < n + 1; ++i) {
            if (record.size() == k) return;
            string tmp = to_string(i);
            if (s.find(tmp) != string::npos) {
                continue;
            }
            s += tmp;
            helper(record, s, k, n);
            if (record.size() == k) return;
            s.erase(s.length() - 1);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol = Solution();
    sol.getPermutation(3, 3);
    return 0;
}
