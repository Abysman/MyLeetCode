//
//  main.cpp
//  428.Serialize and Deserialize N-ary Tree
//
//  Created by stevenxu on 11/22/19.
//  Copyright © 2019 stevenxu. All rights reserved.
//

#include <iostream>
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
private:
    void serialize_helper(Node* root, string& s) {
        if (!root) return;
        s += " " + to_string(root->val) + " " + to_string(root->children.size());
        for (auto child: root->children) serialize_helper(child, s);
    }
    
    Node* deserialize_helper(stringstream& s) {
        int val, children_size;
        if (s >> val >> children_size) {
            auto root = new Node();
            root->val = val;
            for (int i = 0; i < children_size; ++i) root->children.push_back(deserialize_helper(s));
            return root;
        }
        return nullptr;
    }
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res =  "";
        serialize_helper(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream ss(data);
        return deserialize_helper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
