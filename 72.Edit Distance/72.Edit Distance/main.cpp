//
//  main.cpp
//  72.Edit Distance
//
//  Created by stevenxu on 9/10/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1_length = word1.size(), word2_length = word2.size();
        vector<vector<int>> record(word1_length + 1, vector<int> (word2_length + 1, 0));
        for (int i = 1; i <= word1_length; ++i) {
            record[i][0] = i;
        }
        for (int j = 1; j <= word2_length; ++j) {
            record[0][j] = j;
        }
        for (int i = 1; i <= word1_length; ++i) {
            for (int j = 1; j <= word2_length; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    record[i][j] = record[i - 1][j - 1];
                } else {
                    record[i][j] = min(record[i - 1][j - 1], min(record[i - 1][j], record[i][j - 1])) + 1;
                }
            }
        }
        return record[word1_length][word2_length];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
