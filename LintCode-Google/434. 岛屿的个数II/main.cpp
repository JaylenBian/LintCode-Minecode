//
//  main.cpp
//  434. 岛屿的个数II
//
//  Created by 边俊林 on 2019/3/1.
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
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        nRows = n;
        if (nRows <= 0) return {};
        nCols = m;
        if (nCols <= 0) return {};

        vector<bool> grid = vector<bool>(n * m, false);
        UnionFind(grid, nRows, nCols);
        vector<int> res;
        nIslandCount = 0;
        for (auto elems: operators) {
            AddNode(grid, elems.x, elems.y);
            res.push_back(nIslandCount);
        }
        return res;
    }

private:
    vector<int> parent;
    int nRows, nCols;
    int nIslandCount;
    const int dirRow[4] = {0, 0, -1, 1};
    const int dirCol[4] = {-1, 1, 0, 0};

    void UnionFind(vector<bool>& grid, int nRows, int nCols) {
        parent = vector<int>(nRows * nCols);
        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; j < nCols; ++j) {
                if (grid[idx(i, j)])
                    parent[idx(i, j)] = idx(i, j);
                else
                    parent[idx(i, j)] = -1;
            }
        }
    }

    int Find(int idx) {
        if (idx == parent[idx]) {
            return parent[idx];
        }
        return parent[idx] = Find(parent[idx]);
    }

    bool Union(int idx1, int idx2) {
        int p1 = Find(idx1);
        int p2 = Find(idx2);
        if (p1 == p2) return false;
        parent[p1] = p2;
        return true;
    }

    void AddNode(vector<bool>& grid, int row, int col) {
        if (grid[idx(row, col)]) return;
        grid[idx(row, col)] = true;
        parent[idx(row, col)] = idx(row, col);
        ++nIslandCount;

        for (int i = 0; i < 4; ++i) {
            int toRow = row + dirRow[i];
            int toCol = col + dirCol[i];
            if (toRow >= 0 && toRow < nRows && toCol >= 0 && toCol < nCols && grid[idx(toRow, toCol)]) {
                if (Union(idx(row, col), idx(toRow, toCol)))
                    --nIslandCount;
            }
        }
    }

    int idx(int row, int col) {
        return row * nCols + col;
    }
};

/// Tips:
// 并查集。注意最重要的优化点：由于是动态添加，没必要每次都计算并查集的集合数，初始化时集合数为0，每次添加一个点时++cnt，若成功合并，则--cnt.

int main() {

    Solution sol = Solution();
    int n = 4, m = 5;
    vector<Point> opt = {
        Point(1, 1), Point(0, 1), Point(3, 3), Point(3, 4)
    };
//    int n = 2, m = 2;
//    vector<Point> opt = {
//        Point(0, 0), Point(1, 1), Point(1, 0), Point(0, 1)
//    };
    vector<int> res = sol.numIslands2(n, m, opt);
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
