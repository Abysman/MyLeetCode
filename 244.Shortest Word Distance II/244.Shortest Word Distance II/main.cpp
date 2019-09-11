//
//  main.cpp
//  244.Shortest Word Distance II
//
//  Created by stevenxu on 9/10/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0;i < words.size(); ++i) {
            wordMap[words[i]].push_back(i);
        }
        
    }
    int shortest(string word1, string word2) {
        int  i= 0, j = 0, dist = INT_MAX;
        while (i < wordMap[word1].size() && j <wordMap[word2].size()) {
            dist = min(dist, abs(wordMap[word1][i] - wordMap[word2][j]));
            wordMap[word1][i] < wordMap[word2][j] ? i++: j++;
        }
        return dist;
    }
private:
    unordered_map<string, vector<int>> wordMap;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
