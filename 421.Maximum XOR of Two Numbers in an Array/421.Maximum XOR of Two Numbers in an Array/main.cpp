//
//  main.cpp
//  421.Maximum XOR of Two Numbers in an Array
//
//  Created by stevenxu on 1/23/20.
//  Copyright © 2020 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxResult = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            mask = mask | (1 << i);
            unordered_set<int> s;
            for (int num: nums) {
                int leftPart = num & mask;
                s.insert(leftPart);
            }
            int greedyTry = maxResult | (1 << i);
            for (int leftPart: s) {
                if (s.find(leftPart ^ greedyTry) != s.end()) {
                    maxResult = greedyTry;
                    break;
                }
            }
        }
        return maxResult;
    }
};
class TrieNode {
public:
    TrieNode* next[2];
    TrieNode () {
        next[0] = nullptr;
        next[1] = nullptr;
    }
};

class Solution {
private:
    TrieNode* buildTree(vector<int>& nums) {
        TrieNode *root = new TrieNode(), *curr = root;
        for (int num: nums) {
            curr = root;
            for (int i = 31; i >= 0; --i) {
                int currIndex = (num >> i) & 1;
                if (curr->next[currIndex] == nullptr) {
                    curr->next[currIndex] = new TrieNode();
                }
                curr = curr->next[currIndex];
            }
        }
        return root;
    }
    
    int helper(int num, TrieNode* root) {
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            int index = (num >> i) & 1;
            if (root->next[index ^ 1] == nullptr) {
                root = root->next[index];
            } else {
                res += (1 << i);
                root = root->next[index ^ 1];
            }
        }
        return res;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *root = buildTree(nums);
        int res = 0;
        for (int num: nums) {
            res = max(res, helper(num, root));
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
