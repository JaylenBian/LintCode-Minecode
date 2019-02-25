//
//  main.cpp
//  137. 克隆图
//
//  Created by 边俊林 on 2019/2/25.
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
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if (node == nullptr) return nullptr;
        
        queue<UndirectedGraphNode*> Q;
        unordered_map<int, UndirectedGraphNode*> mp;
        unordered_set<int> vis;
        UndirectedGraphNode* pHead = new UndirectedGraphNode(node->label);
        mp[node->label] = pHead;
        Q.push(node);
        while (!Q.empty()) {
            UndirectedGraphNode* pNode = Q.front();
            Q.pop();
            if (vis.find(pNode->label) != vis.end()) continue;
            vis.insert(pNode->label);
            UndirectedGraphNode* pCloneNode = getCloneNode(mp, pNode->label);
            
            // Clone Neighbors
            auto neighbors = pNode->neighbors;
            for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
                UndirectedGraphNode* pNeighbor = *it;
                pCloneNode->neighbors.push_back(getCloneNode(mp, pNeighbor->label));
                Q.push(pNeighbor);
            }
        }
        
        return pHead;
    }
    
private:
    UndirectedGraphNode* getCloneNode(unordered_map<int, UndirectedGraphNode*>& mp, int label) {
        UndirectedGraphNode* pCloneNode;
        if (mp.find(label) != mp.end()) {
            pCloneNode = mp[label];
        } else {
            pCloneNode = new UndirectedGraphNode(label);
            mp[label] = pCloneNode;
        }
        return pCloneNode;
    }
};

/// Tips:
// BFS，通过一个HashTable存储已经匹配的点

int main() {
    
    Solution sol = Solution();
    
    UndirectedGraphNode* n0 = new UndirectedGraphNode(0);
    UndirectedGraphNode* n1 = new UndirectedGraphNode(1);
    UndirectedGraphNode* n2 = new UndirectedGraphNode(2);
    n0->neighbors = {n1, n2};
    n1->neighbors = {n2};
    n2->neighbors = {n2};
    
    UndirectedGraphNode* pNode = sol.cloneGraph(n0);
    cout << pNode->label << endl;
    
    return 0;
}
