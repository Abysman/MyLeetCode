//
//  main.cpp
//  008.Sort with Two Stacks
//
//  Created by Abysman on 2019/2/14.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;;

vector<int> sort(vector<int> n) {
    vector<int> res;
    stack<int> s1, s2;
    for (int num: n) {
        s1.push(num);
    }
    while (!s1.empty()) {
        int curr = s1.top();
        s1.pop();
        if (s2.empty()) s2.push(curr);
        else {
            while (!s2.empty() && curr < s2.top()) {
                int tmp = s2.top();
                s2.pop();
                s1.push(tmp);
            }
            s2.push(curr);
        }
    }
    while (!s2.empty()) {
        res.push_back(s2.top());
        s2.pop();
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> test_case = {1,2,7,4,2,3,8,1,10,3,6,7,1,2,3};
    vector<int> res = sort(test_case);
    for (int n: res) {
        cout << n << " ";
    }
    cout << "\n";
    return 0;
}
