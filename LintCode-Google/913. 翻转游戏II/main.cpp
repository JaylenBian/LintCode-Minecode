//
//  main.cpp
//  913. 翻转游戏II
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
    bool canWin(string &s) {
        if (map.find(s) != map.end()) return map[s];
        
        for (int i = 1; i < s.length(); ++i) {
            if (s[i-1] == '+' && s[i] == '+') {
                s.replace(i-1, 2, "--");
                if (!canWin(s)) {
                    s.replace(i-1, 2, "++");
                    map[s] = true;
                    return true;
                }
                s.replace(i-1, 2, "++");
            }
        }
        map[s] = false;
        return false;
    }
    
private:
    unordered_map<string, bool> map;
};

/// Tips:
// 博弈论，当前回合的必胜建立在上一回合不能胜利之上，转化为递归过程。
// 优化：字符串是否能胜利可以缓存起来，string可以直接替换并在递归返回时换回，避免每次生成新的。


int main() {
    
    Solution sol = Solution();
    string s1 = "++++";
    string s2 = "+++++";
    string s3 = "+++++++++++++++++++++";
    bool res = sol.canWin(s3);
    
    cout << (res ? "true" : "false") << endl;
    
    return 0;
}
