//
//  main.cpp
//  178. 图是否是树
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
class Solution {
public:
    bool validTree(int n, vector<vector<int>> &edges) {
        if (edges.size() != n-1)
            return false;
        
        UnionFind(n);
        for (int i = 0; i < edges.size(); ++i) {
            Union(edges[i][0], edges[i][1]);
        }
        return GroupCount() == 1;
    }
    
private:
    vector<int> parent;
    int nCount;
    
    int GroupCount() {
        return nCount;
    }
    
    void UnionFind(int size) {
        if (size <= 0)
            throw invalid_argument("Size should more than 0");
        
        parent = vector<int>(size);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
        nCount = size;
    }
    
    int Find(int n) {
        if (n == parent[n] )
            return n;
        parent[n] = Find(parent[n]);
        return parent[n];
    }
    
    void Union(int u, int v) {
        int p1 = Find(u);
        int p2 = Find(v);
        if (p1 == p2) return;
        
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] == p1)
                parent[i] = p2;
        }
        nCount--;
    }
};

/// Tips:
// 需要满足两个条件：1. 是无环图 2.是连通图
// 当edge数量等于n-1时，则满足亮点。连通图可通过并查集

int main() {
    
    Solution sol = Solution();
//    vector<vector<int>> edges = {
//        {0, 1}, {0, 2}, {0, 3}, {1, 4}
//    };
    vector<vector<int>> edges = {
        {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}}
    };
    int n = 5;
    bool res = sol.validTree(n, edges);
    cout << (res ? "true" : "false") << endl;
    
    return 0;
}
