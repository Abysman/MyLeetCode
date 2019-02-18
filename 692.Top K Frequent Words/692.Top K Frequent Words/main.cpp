//
//  main.cpp
//  692.Top K Frequent Words
//
//  Created by Abysman on 2019/2/17.
//  Copyright © 2019 Abysman. All rights reserved.
//

#include <iostream>

class Solution {
public:
    struct comp{
        bool operator()(pair<string, int> a, pair<string, int> b) {
            if (a.second == b.second) return a.first < b.first;
            else return a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        map<string, int> m;
        priority_queue<pair<string, int>, vector<pair<string, int>>, comp> pq;
        int count = k;
        for (int i = 0; i < (int)words.size(); ++i) {
            m[words[i]]++;
        }
        for (auto word: m) {
            cout << word.first << " " << word.second << "\n";
            pq.push(make_pair(word.first, word.second));
            if (pq.size() > k) pq.pop();
        }
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
