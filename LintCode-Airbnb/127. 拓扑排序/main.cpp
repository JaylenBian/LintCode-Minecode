//
//  main.cpp
//  127. 拓扑排序
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

const int MAXN = 1e5+10;

struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /*
     * @param graph A list of Directed graph node
     * @return Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        int vexsum = (int)graph.size();
        list<int> *adjs = new list<int>[vexsum];
        int *indegree = new int[vexsum];
        queue<int> q;
        memset(indegree, 0, vexsum * sizeof(int));
        
        for (int i = 0; i < vexsum; ++i) {
            int label = graph[i]->label;
            for (int j = 0; j < graph[i]->neighbors.size(); ++j) {
                adjs[label].push_back(graph[i]->neighbors[j]->label);
                ++indegree[graph[i]->neighbors[j]->label];
            }
        }
        for (int i = 0; i < vexsum; ++i) {
            int label = graph[i]->label;
            if (indegree[label] == 0) q.push(label);
        }
        vector<DirectedGraphNode *> res;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            for (list<int>::iterator it = adjs[v].begin(); it != adjs[v].end(); ++it) {
                if(--indegree[*it] == 0)    q.push(*it);
            }
            res.push_back(new DirectedGraphNode(v));
        }
        return res;
    }
};

int main() {
    
    return 0;
}
