//
//  main.cpp
//  004.High Five(Amazon)
//
//  Created by Abysman on 2019/1/29.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;;

struct Result {
    int id, score;
    Result (int id , int score) {
        id = id;
        score = score;
    }
};

map<int, double> getHighFive(vector<Result> scores) {
    map<int, priority_queue<int, vector<int>>> pValue;
    for (Result res: scores) {
        int id = res.id;
        if (pValue.find(id) != pValue.end()) {
            pValue[id].push(res.score);
            if (pValue[id].size() > 5) pValue[id].pop();
        }
    }
    map<int, double> res;
    for (auto &p:pValue) {
        double sum = 0;
        priority_queue<int, vector<int>> curr = p.second;
        for (int i = 0; i < 5; ++i) {
            sum += curr.top();
            curr.pop();
        }
        res[p.first] = sum / 5.0;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
