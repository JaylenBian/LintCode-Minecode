//
//  main.cpp
//  104. 合并k个排序链表
//
//  Created by 边俊林 on 2019/2/24.
//  Copyright © 2019 边俊林. All rights reserved.
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
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

struct cmp {
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }
        
        ListNode* pHead = new ListNode(-1);
        ListNode* pNode = pHead;
        while (!pq.empty()) {
            pNode->next = pq.top();
            pNode = pNode->next;
            pq.pop();
            if (pNode->next != nullptr) {
                pq.push(pNode->next);
                pNode->next = nullptr;
            }
        }
        
        pNode = pHead;
        pHead = pHead->next;
        delete pNode;
        return pHead;
    }
    
private:
    
};

/// Tips:
// 方法1：
// 使用优先队列维护一个最小堆，了解重写优先队列的方法
//
// 方法2:
// 分治法，每次合并两个链表，从而演化成递归过程，每次减少一半链表数量。

int main() {
    
    Solution sol = Solution();
    
    ListNode* a1 = new ListNode(2);
    ListNode* a2 = new ListNode(6);
    ListNode* b1 = new ListNode(5);
    ListNode* c1 = new ListNode(7);
    a1->next = a2;
    
    vector<ListNode*> lists = {a1, b1, c1};
    auto res = sol.mergeKLists(lists);
    
    auto pNode = res;
    while (pNode != nullptr) {
        cout << pNode->val << " -> ";
        pNode = pNode->next;
    }
    cout << "nullptr" << endl;
    
    return 0;
}
