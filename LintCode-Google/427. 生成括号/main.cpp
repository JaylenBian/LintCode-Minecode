//
//  main.cpp
//  427. 生成括号
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
    vector<string> generateParenthesis(int n) {
        if (n <= 0) return {};
        
        vector<string> res;
        vector<char> path;
        GenerateString("", 0, 0, n, res);
        return res;
    }
    
private:
    void GenerateString(string str, int l, int r, int n, vector<string>& res) {
        if (l == n) {
            str += string(l-r, ')');
            res.push_back(str);
            return;
        }
        if (l > r) {
            GenerateString(str + ")", l, r+1, n, res);
        }
        GenerateString(str+"(", l+1, r, n, res);
    }
};

/// Tips:
// 

int main() {
    
    Solution sol = Solution();
    int n = 3;
//    int n = 2;
    auto res = sol.generateParenthesis(n);
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it << endl;
    }
    
    return 0;
}
