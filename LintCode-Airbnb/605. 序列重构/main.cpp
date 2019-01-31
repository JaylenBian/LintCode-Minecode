//
//  main.cpp
//  605. 序列重构
//
//  Created by 边俊林 on 2018/8/25.
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

class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        if (org.size() == 0) return true;
        int n = (int)org.size(), last = n-1;
        vector<int> matched (n+1, 0), pos(n+1, 0);
        for (int i = 0; i < n; ++i) {
            pos[org[i]] = i;
        }
        bool onlyOneMatched = false;
        for (vector<int> seq : seqs) {
            for (int i = 0; i < seq.size(); ++i) {
                onlyOneMatched = true;
                if (seq[i] <= 0 || seq[i] > n) return false;
                if (i == 0) continue;
                int pre = seq[i-1], cur = seq[i];
                if (pos[pre] >= pos[cur]) return false;
                if (matched[cur] == 0 && pos[pre]+1 == pos[cur]) {
                    matched[cur] = 1;
                    last--;
                }
            }
        }
        return last == 0 && onlyOneMatched;
    }
};

int main() {
    
    Solution sol = Solution();
//    vector<int> v1 = {1, 2, 3};
//    vector<vector<int>> v2 = {{1, 2}, {1, 3}, {2, 3}};
//    vector<int> v1 = {4, 1, 5, 2, 6, 3};
//    vector<vector<int>> v2 = {{5, 2, 6, 3}, {4, 1, 5, 2}};
    vector<int> v1 = {};
    vector<vector<int>> v2 = {{}};
    bool res = sol.sequenceReconstruction(v1, v2);
    cout << (res ? "true" : "false") << endl;
    
    return 0;
}
