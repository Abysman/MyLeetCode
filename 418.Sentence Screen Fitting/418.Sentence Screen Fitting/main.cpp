//
//  main.cpp
//  418.Sentence Screen Fitting
//
//  Created by stevenxu on 11/27/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int res = 0;
        vector<int> record(sentence.size(), -1);
        int numUsed = 0, start = 0;
        while (rows > 0) {
            start = numUsed % sentence.size();
            if (record[start] == -1) {
                int count = 0, len = 0;
                for (int i = start; len < cols; i = (i + 1) % sentence.size(), count++) {
                    if (len + sentence[i].size() > cols) break;
                    len += sentence[i].size() + 1;
                }
                numUsed += count;
                record[start] = count;
            } else {
                numUsed += record[start];
            }
            rows--;
        }
        return numUsed / sentence.size();
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
