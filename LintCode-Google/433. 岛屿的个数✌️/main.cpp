//
//  main.cpp
//  433. 岛屿的个数
//
//  Created by 边俊林 on 2019/2/28.
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
    int numIslands(vector<vector<bool>> &grid) {
        nRows = (int)grid.size();
        if (nRows <= 0) return 0;
        nCols = (int)grid[0].size();
        if (nCols <= 0) return 0;

        UnionFind(grid, nRows, nCols);
        vector<bool> vis = vector<bool>(nRows * nCols, false);
        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; j < nCols; ++j) {
                dfs(grid, i, j, i, j, vis);
            }
        }
        return CountIslands();
    }

private:
    vector<int> parent;
    int nRows, nCols;
    bool hasSea;
    const int dirRow[4] = {0, 0, -1, 1};
    const int dirCol[4] = {-1, 1, 0, 0};

    void dfs(vector<vector<bool>> &grid, int currRow, int currCol, int fromRow, int fromCol, vector<bool>& vis) {
        if (vis[idx(currRow, currCol)] || !grid[currRow][currCol]) return;
        vis[idx(currRow, currCol)] = true;

        Union(idx(currRow, currCol), idx(fromRow, fromCol));
        for (int i = 0; i < 4; ++i) {
            int toRow = currRow + dirRow[i];
            int toCol = currCol + dirCol[i];
            if (toRow >= 0 && toRow < nRows && toCol >= 0 && toCol < nCols) {
                if (!vis[idx(toRow, toCol)] && grid[toRow][toCol])
                    dfs(grid, toRow, toCol, currRow, currCol, vis);
            }
        }
    }

    int CountIslands() {
        unordered_set<int> islands = unordered_set<int>(parent.begin(), parent.end());
        return (int)islands.size() - hasSea;
    }

    void UnionFind(vector<vector<bool>>& grid, int nRows, int nCols) {
        parent = vector<int>(nRows * nCols);
        hasSea = false;
        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; j < nCols; ++j) {
                if (grid[i][j] == false) {
                    hasSea = true;
                    parent[idx(i, j)] = -1;
                } else {
                    parent[idx(i, j)] = idx(i, j);
                }
            }
        }
    }

    int Find(int idx) {
        if (idx == parent[idx]) {
            return parent[idx];
        }
        return parent[idx] = Find(parent[idx]);
    }

    void Union(int idx1, int idx2) {
        int p1 = Find(idx1);
        int p2 = Find(idx2);
        if (p1 == p2) return;
        parent[p1] = p2;
    }

    int idx(int row, int col) {
        return row * nCols + col;
    }
};

/// Tips:
// 并查集+DFS，注意并查集的写法，Union的时候没必要把所有parent为当前被变更的节点的节点更新

int main() {

    Solution sol = Solution();
    vector<vector<bool>> grid = {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1}
    };
    int res = sol.numIslands(grid);
    cout << res << endl;

    return 0;
}
