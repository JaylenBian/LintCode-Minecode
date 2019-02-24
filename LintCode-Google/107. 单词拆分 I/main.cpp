//
//  main.cpp
//  107. 单词拆分 I
//
//  Created by 边俊林 on 2019/2/24.
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
    bool wordBreak(string &s, unordered_set<string> &dict) {
        if (s.empty()) return true;
        if (dict.empty()) return false;
        
        bool* dp = new bool[s.length() + 1];
        memset(dp, 0, s.length()+1);
        dp[0] = true;
        
        int nLength = (int)s.length();
        int maxWordLen = maxLength(dict);
        for (int i = 1; i <= nLength; ++i) {
            for (int j = 1; j <= maxWordLen && j <= i; ++j) {
                if (dp[i-j]) {
                    string word = s.substr(i-j, j);
                    if (dict.find(word) != dict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[nLength];
    }
    
private:
    int maxLength(unordered_set<string> &dict) {
        int res = 0;
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            if ((*it).length() > res)
                res = (int)(*it).length();
        }
        return res;
    }
};

/// Tips:
// dp，dp[i]表示字符串长度为i的位置是否可达。枚举每个区间，判断是否可以状态转移。

int main() {
    
    Solution sol = Solution();
    string s = "lintcode";
    unordered_set<string> dict = {
        "lint", "code"
    };
//    string s = "a";
//    unordered_set<string> dict = {
//        "b"
//    };
    bool res = sol.wordBreak(s, dict);
    cout << (res ? "true" : "false") << endl;
    
    return 0;
}
