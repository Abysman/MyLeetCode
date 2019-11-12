//
//  main.cpp
//  1255.Maximum Score Words Formed by Letters
//
//  Created by stevenxu on 11/12/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> counts(26);
        for (char c: letters) counts[c - 'a']++;
        return dfs(words, letters, score, counts, 0);
    }
    
    int dfs(vector<string>& words, vector<char>& letters, vector<int>& score, vector<int>& counts, int i) {
        if (i >= words.size()) return 0;
        int skipGain = dfs(words, letters, score, counts, i + 1), formed = 1, gain = 0;
        vector<int> tmp(counts.begin(), counts.end());
        for (char c: words[i]) {
            if (--tmp[c-'a'] < 0) formed = 0;
            gain += score[c - 'a'];
        }
        return max(skipGain, formed ? gain + dfs(words, letters, score, tmp, i + 1) : 0);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
