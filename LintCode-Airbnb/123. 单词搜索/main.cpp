//
//  main.cpp
//  123. 单词搜索
//
//  Created by 边俊林 on 2018/8/17.
//  Copyright © 2018 minecode. All rights reserved.
//

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

// Solution:
// DFS

const int MAXN = 1e3+10;
int nxt[4][2] = {
    {-1, 0}, { 1, 0 }, {0, -1}, {0, 1}
};

class Solution {
public:
    /**
     * @param board A list of lists of character
     * @param word A string
     * @return A boolean
     */
    bool exist(vector<vector<char>> &board, string &word) {
        if (board.size() == 0) return false;
        int n = (int)board.size(), m = (int)board[0].size();
        bool vis[MAXN][MAXN] = {{false}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, vis, i, j, 0)) {return true;}
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>> &board, string &word, bool vis[MAXN][MAXN], int x, int y, int idx) {
        if (idx == word.length()) return true;
        if (x>=0 && x<board[0].size() && y>=0 && y<board.size() && !vis[x][y] && board[y][x]==word[idx]) {
            vis[x][y] = true;
            for (int i = 0; i < 4; ++i) {
                int tx = x + nxt[i][0];
                int ty = y + nxt[i][1];
                if (dfs(board, word, vis, tx, ty, idx+1)) { return true; }
            }
            vis[x][y] = false;
        }
        return false;
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
    
    Solution sol = Solution();
    vector<vector<char> > board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
        };
    string word = "ABCB";
    bool res = sol.exist(board, word);
    cout << (res ? "true" : "false") << endl;
    
    return 0;
}
