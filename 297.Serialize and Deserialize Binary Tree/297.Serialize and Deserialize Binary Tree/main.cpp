//
//  main.cpp
//  297.Serialize and Deserialize Binary Tree
//
//  Created by Abysman on 2018/9/25.
//  Copyright © 2018年 Abysman. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    // Encodes a tree to a single string.
    
    //     string serialize(TreeNode* root) {
    //         ostringstream out;
    //         queue<TreeNode*> q;
    //         if (root) q.push(root);
    //         while (!q.empty()) {
    //             TreeNode *t = q.front(); q.pop();
    //             if (t) {
    //                 out << t->val << ' ';
    //                 q.push(t->left);
    //                 q.push(t->right);
    //             } else {
    //                 out << "# ";
    //             }
    //         }
    //         return out.str();
    //     }
    string serialize(TreeNode* root) {
        if (!root) return "";
        string res = "";
        queue<TreeNode* > q;
        q.push(root);
        int s = q.size();
        while (!q.empty()) {
            s = q.size();
            
            TreeNode* curr = q.front();
            q.pop();
            if (curr) {
                res += to_string(curr->val) + " ";
                q.push(curr->left);
                q.push(curr->right);
            }
            else {
                res += "# ";
            }
            
        }
        cout << "res:" << res << "\n";
        return res;
    }
    
    //     // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        istringstream in(data);
        string val;
        in >> val;
        TreeNode* curr = new TreeNode(stoi(val));
        TreeNode* res = curr;
        queue<TreeNode* > q;
        q.push(curr);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (!(in >> val)) break;
            cout << val << "\n";
            if (val != "#") {
                TreeNode* newNode = new TreeNode(stoi(val));
                curr->left = newNode;
                q.push(newNode);
            }
            if (!(in >> val)) break;
            if (val != "#") {
                TreeNode* newNode = new TreeNode(stoi(val));
                curr->right = newNode;
                q.push(newNode);
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* res = deserialize("1 2 3 # # 4 5 # # # #");
    return 0;
}
