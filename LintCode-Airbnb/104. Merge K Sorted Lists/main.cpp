//
//  main.cpp
//  104. Merge K Sorted Lists
//
//  Created by 边俊林 on 2018/8/16.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ------------------------------------------------- *\
 https://www.lintcode.com/problem/two-sum/description
\* ------------------------------------------------- */

#include <map>
#include <set>
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

// Solution
// Simulation

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    /**
     * @param lists a list of ListNode
     * @return The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<int> v;
        for (int i = 0; i < lists.size(); ++i) {
            ListNode *node = lists[i];
            while (node != NULL) {
                v.push_back(node->val);
                node = node->next;
            }
        }
        sort(v.begin(), v.end());
        
        ListNode *start = v.size() > 0 ? (new ListNode(v[0])) : NULL;
        ListNode *last = start;
        for (int i = 1; i < v.size(); ++i) {
            last->next = new ListNode(v[i]);
            last = last->next;
        }
        return start;
    }
};

// Tool Function List
void printVector(vector<int> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c%d", it==v.begin() ? '\0' : ' ', *it);
    }
    printf("]\n");
}

int main() {
    
    return 0;
}
