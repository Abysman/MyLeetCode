//
//  main.cpp
//  1268.Search Suggestions System
//
//  Created by stevenxu on 11/26/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<string>::iterator iter = products.begin();
        vector<vector<string>> res;
        string s = "";
        
        for (char c: searchWord) {
            vector<string> curr;
            s += c;
            iter = lower_bound(iter, products.end(), s);
            for (int i = 0; i < 3 && (iter + i) < products.end(); ++i) {
                string tmp = *(iter + i);
                if (tmp.find(s)) break;
                curr.push_back(tmp);
            }
            res.push_back(curr);
        }
        
        return res;
    }
};
class TrieNode {
public:
    map<char, TrieNode*> next;
    bool isWord = false;
    TrieNode() {}
    
    void addWord(string word) {
        TrieNode* curr = this;
        for (char c: word) {
            if (curr->next.find(c) == curr->next.end()) curr->next[c] = new TrieNode();
            curr = curr->next[c];
        }
        curr->isWord = true;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode *root = new TrieNode();
        vector<vector<string>> res;
        string s = "";
        for (string p: products) {
            root->addWord(p);
        }
        for (char c: searchWord) {
            vector<string> curr;
            if (root == nullptr || root->next.find(c) == root->next.end()) {
                res.push_back(curr);
                root = nullptr;
                continue;
            }
            s += c;
            helper(res, curr, root->next[c], s);
            res.push_back(curr);
            root = root->next[c];
        }
        return res;
    }
    
    void helper(vector<vector<string>> &res, vector<string> &curr, TrieNode *node, string s) {
        TrieNode *tmp = node;
        if (node->isWord && curr.size() < 3) curr.push_back(s);
        for (auto elem = tmp->next.begin(); elem != tmp->next.end(); elem++) {
            if (curr.size() == 3) return;
            helper(res, curr, elem->second, s + elem->first);
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
