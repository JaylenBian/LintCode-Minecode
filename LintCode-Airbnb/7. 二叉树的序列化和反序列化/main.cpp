//
//  main.cpp
//  7. 二叉树的序列化和反序列化
//
//  Created by 边俊林 on 2018/8/25.
//  Copyright © 2018 minecode. All rights reserved.
//

#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//


class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        queue<TreeNode *> q;
        q.push(root);
        stringstream ss;
        
        while (!q.empty()) {
            TreeNode *head = q.front();
            q.pop();
            
            if (head != NULL) {
                ss << head->val << ',';
                q.push(head->left);
                q.push(head->right);
            } else {
                ss << "#" << ',';
            }
        }
        return ss.str();
    }
    
    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        istringstream iss(data);
        TreeNode *root = stringToNode(iss);
        if (root == NULL) return NULL;
        
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *head = q.front();
            q.pop();
            
            head->left = stringToNode(iss);
            head->right = stringToNode(iss);
            if (head->left != NULL) q.push(head->left);
            if (head->right  != NULL) q.push(head->right);
        }
        return root;
    }
private:
    TreeNode *stringToNode(istringstream &iss) {
        string res;
        getline(iss, res, ',');
        return res == "#" ? NULL : new TreeNode(stoi(res));
    }
};

int main() {
    
    TreeNode *root = new TreeNode(1);
//    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);
    root->right = right;
    
    Solution sol = Solution();
    string newData = sol.serialize(root);
    cout << newData << endl;
    
    return 0;
}
