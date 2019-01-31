//
//  main.cpp
//  1049. Pyramid Transition Matrix
//
//  Created by 边俊林 on 2018/8/30.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ---------------------------------------------------------------------- *\
 https://www.lintcode.com/problem/pyramid-transition-matrix/description
\* ---------------------------------------------------------------------- */

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
     * @param bottom a string
     * @param allowed a list of strings
     * @return return a boolean
     */
    bool pyramidTransition(string &bottom, vector<string> &allowed) {
        unordered_map<string, unordered_set<char>> mp;
        for (string str : allowed) {
            mp[str.substr(0, 2)].insert(str[2]);
        }
        return pyramidBuilder(bottom, "", mp);
    }
    
private:
    bool pyramidBuilder(string curr, string nxt, unordered_map<string, unordered_set<char>>& mp) {
        // If is the top layer, pyramid build success
        if (nxt.size() == 1 && curr.size() == 2) return true;
        // If next layer build success, start to build the next layer of next
        if (nxt.size() == curr.size() - 1) return pyramidBuilder(nxt, "", mp);
        // If next layer have't done yet, just keep building
        int p = (int)nxt.size();
        string letter = curr.substr(p, 2);
        if (mp.count(letter)) {
            for (char c : mp[letter]) {
                if (pyramidBuilder(curr, string(nxt).append(string(1, c)), mp)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol = Solution();
    string bottom = "XYZ";
    vector<string> allowed = {"XYD", "YZE", "DEA", "FFF"};
//    vector<string> allowed = {"XXX", "XXY", "XYX", "XYY", "YXZ"};
    bool res = sol.pyramidTransition(b吗 ottom, allowed);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
