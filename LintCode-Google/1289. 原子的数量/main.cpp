//
//  main.cpp
//  1289. 原子的数量
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
#define umap unordered_map

using namespace std;

/// Solution:
//
class Solution {
public:
    string countOfAtoms(string &formula) {
        int pos = 0;
        auto parsedMap = atomsParser(formula, pos);
        map<string, int> orderedMap;
        for (auto elem : parsedMap) {
            orderedMap[elem.first] = elem.second;
        }
        string res;
        for (auto elem : orderedMap) {
            res += elem.first;
            res += elem.second == 1 ? "" : to_string(elem.second);
        }
        return res;
    }
    
private:
    umap<string, int> atomsParser(string& formula, int& pos) {
        umap<string, int> parsedMap;
        while (pos < formula.length()) {
            if (formula[pos] == '(') {
                auto parsedRes = atomsParser(formula, ++pos);
                for (auto elem : parsedRes) {
                    parsedMap[elem.first] += elem.second;
                }
            } else if (formula[pos] == ')') {
                int digitBegin = ++pos;
                while (pos < formula.length() && isdigit(formula[pos])) ++pos;
                string digitStr = formula.substr(digitBegin, pos-digitBegin);
                int multiplier = stoi(digitStr);
                for (auto elem : parsedMap) {
                    parsedMap[elem.first] *= multiplier;
                }
                return parsedMap;
            } else {
                if (!isupper(formula[pos]))
                    throw new invalid_argument("Wrong Formula");
                int nameBegin = pos++;
                while (pos < formula.length() && islower(formula[pos])) ++pos;
                string nameStr = formula.substr(nameBegin, pos-nameBegin);
                int digitbegin = pos;
                while (pos < formula.length() && isdigit(formula[pos])) ++pos;
                string digitStr = formula.substr(digitbegin, pos-digitbegin);
                int addend = digitStr.empty() ? 1 : stoi(digitStr);
                parsedMap[nameStr] += addend;
            }
        }
        return parsedMap;
    }
};

/// Tips:
// 把该解析过程分解为每个段的解析子过程，则根据括号将每个段分隔，括号后紧跟的数字为乘数。每个字母后面跟的为加数。


int main() {
    
    Solution sol = Solution();
    string formula1 = "H1O2";
    string formula2 = "H2O2He3Mg4";
    
    auto res = sol.countOfAtoms(formula2);
    
    cout << res << endl;
    
    return 0;
}
