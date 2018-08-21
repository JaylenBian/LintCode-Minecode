//
//  main.cpp
//  380. 两个链表的交叉
//
//  Created by 边俊林 on 2018/8/21.
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    /*
     * @param headA the first list
     * @param headB the second list
     * @return a ListNode
     */
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
        if (headA == NULL || headB == NULL) return NULL;
        int len1 = 0, len2 = 0;
        ListNode *p1 = headA, *p2 = headB;
        while (p1->next != NULL) {
            len1++;
            p1 = p1->next;
        }
        while (p2->next != NULL) {
            len2++;
            p2 = p2->next;
        }
        if (p2 != p1 && p1 != NULL) {
            return NULL;
        }
        
        p1 = headA;
        p2 = headB;
        if (len1 > len2) {
            for (int i = 0; i < len1-len2; ++i) {
                p1 = p1->next;
            }
        } else if (len2 > len1) {
            for (int i = 0; i < len2-len1; ++i) {
                p2 = p2->next;
            }
        }
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

int main() {
    
    return 0;
}
