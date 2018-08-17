//
//  main.cpp
//  132. 单词搜索 II
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

// Solution
// DFS

const int MAXN = 1e3+10;
int nxt[4][2] = {
    {-1, 0}, { 1, 0 }, {0, -1}, {0, 1}
};

class Solution {
public:
    /**
     * @param board A list of lists of character
     * @param words A list of string
     * @return A list of string
     */
    vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
        if (board.size() == 0) { return vector<string>();}
        int m = (int)board[0].size(), n = (int)board.size();
        int num = (int)words.size();
        
        vector<string> res;
        for(int wi = 0; wi < num; ++wi) {
            bool vis[MAXN][MAXN] = {{false}};
            bool flag = false;
            for(int i = 0; i < m; ++i) {
                if (flag) break;
                for(int j = 0; j < n; ++j) {
                    if (dfs(board, words, vis, i, j, wi, 0)) {
                        res.push_back(words[wi]);
                        flag = true;
                        break;
                    }
                }
            }
        }
        return res;
    }
private:
    bool dfs(vector<vector<char>> &board, vector<string> &words, bool vis[MAXN][MAXN], int x, int y, int wi, int idx) {
        if (idx == words[wi].length()) return true;
        if (x>=0 && y>=0 && x<board[0].size() && y<board.size() && !vis[x][y] && board[y][x]==words[wi][idx]) {
            vis[x][y] = true;
            for (int i = 0; i < 4; ++i) {
                int tx = x + nxt[i][0];
                int ty = y + nxt[i][1];
                if (dfs(board, words, vis, tx, ty, wi, idx+1)) return true;
            }
            vis[x][y] = false;
        }
        return false;
    }
};

int main() {
    
    Solution sol = Solution();
    vector<vector<char>> board = {
        {'d', 'o', 'a', 'f'},
        {'a', 'g', 'a', 'i'},
        {'d', 'c', 'a', 'n'}
    };
    vector<string> words = {"dog", "dad", "dgdg", "can", "again"};
    vector<string> res = sol.wordSearchII(board, words);
    
    for (auto it : res) {
        cout << it << endl;
    }
    
    return 0;
}
