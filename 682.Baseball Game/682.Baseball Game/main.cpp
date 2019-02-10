//
//  main.cpp
//  682.Baseball Game
//
//  Created by Abysman on 2019/2/9.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution{
public:
    int calPoints(vector<string>& ops, vector<int> r={}){
        for (string op : ops)
            if      (op=="C") r.pop_back();
            else if (op=="D") r.push_back(2*r.back());
            else if (op=="+") r.push_back(r[int(r.size())-2]+r.back());
            else              r.push_back(stoi(op));
        return accumulate(r.begin(), r.end(), 0);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
