//
//  main.cpp
//  914. 翻转游戏
//
//  Created by 边俊林 on 2019/2/21.
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
    vector<string> generatePossibleNextMoves(string &s) {
        vector<string> res;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i-1] == '+' && s[i] == '+') {
                string tmp = string(s);
                tmp[i-1] = tmp[i] = '-';
                res.push_back(tmp);
            }
        }
        return res;
    }
    
private:
    
};

/// Tips:
// 基础题


int main() {
    
    Solution sol = Solution();
    string s = "---+++-+++-+";
    auto res = sol.generatePossibleNextMoves(s);
    
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it << endl;
    }
    
    return 0;
}
