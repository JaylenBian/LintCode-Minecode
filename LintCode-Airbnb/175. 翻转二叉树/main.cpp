//
//  main.cpp
//  175. 翻转二叉树
//
//  Created by 边俊林 on 2018/8/24.
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
     * @param root a TreeNode, the root of the binary tree
     * @return nothing
     */
    void invertBinaryTree(TreeNode * root) {
        if (root == NULL) return;
        
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
};

int main() {
    
    return 0;
}
