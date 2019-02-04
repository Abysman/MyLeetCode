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

vector<int> topfive(vector<int> a){
    priority_queue<int> q;
    for(int i=0; i< a.size(); i++) q.push( a);
    vector<int> top5;
    int five = 5;
    while(five){
        top5.push_back(q.top());
        q.pop();
        five--;
    }
    return top5;
}

map<int,vector<int> > hfive(vector<Result> tresults){
    map<int, vector<int> > stds_scores;
    for(int i = 0; i< tresults.size(); i++){
        TestResult stdscore = tresults;
        stds_scores[stdscore.studentId].push_back(stdscore.testScore);
    }
    map<int, vector<int> > final;
    map<int, vector<int> >::iterator it;
    for(it = stds_scores.begin(); it != stds_scores.end(); it++){
        int stdid = it->first;
        vector<int> scores = it->second;
        vector<int> top5 = topfive(scores);
        final[stdid] = top5;
    }
    return final;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
