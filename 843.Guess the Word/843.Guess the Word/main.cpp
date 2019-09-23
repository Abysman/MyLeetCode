//
//  main.cpp
//  843.Guess the Word
//
//  Created by stevenxu on 9/23/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0, x = 0; i < 10 && x < 6; ++i) {
            unordered_map<string, int> count;
            for (string w1 : wordlist)
                for (string w2 : wordlist)
                    if (match(w1, w2) == 0)
                        count[w1]++;
            pair<string, int> minimax = make_pair(wordlist[0], 1000);
            for (string w : wordlist)
                if (count[w] <= minimax.second)
                    minimax = make_pair(w, count[w]);
            x = master.guess(minimax.first);
            vector<string> wordlist2;
            for (string w : wordlist)
                if (match(minimax.first, w) == x)
                    wordlist2.push_back(w);
            wordlist = wordlist2;
        }
    }
    
    int match(string a, string b) {
        int matches = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) matches++;
        }
        return matches;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
