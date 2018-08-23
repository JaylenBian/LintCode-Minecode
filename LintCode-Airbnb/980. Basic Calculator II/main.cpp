//
//  main.cpp
//  980. Basic Calculator II
//
//  Created by 边俊林 on 2018/8/22.
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
     * @param s the given expression
     * @return the result of expression
     */
    int calculate(string &s) {
        stack<int> t;
        int n = (int)s.length();
        if (n == 0) return 0;
        
        int num = 0;
        char sign = '+';
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            // on digit
            if (c>='0' && c<='9') {
                int num = 0;
                while (i<n && s[i]>='0' && s[i]<='9') {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                --i;
                
                if (sign == '*') {
                    int last = t.top(); t.pop();
                    t.push(last * num);
                } else if (sign == '/') {
                    int last = t.top(); t.pop();
                    t.push(last / num);
                } else if (sign == '+') {
                    t.push(num);
                } else if (sign == '-') {
                    t.push(-num);
                }
                
                continue;
            }
            // on operator
            if (c=='+' || c=='-' || c=='*' || c=='/') {
                num = 0;
                sign = c;
            }
        }
        int sum = 0;
        while (!t.empty()) {
            sum += t.top(); t.pop();
        }
        return sum;
    }
};

int main() {
    Solution sol = Solution();
    string str = "3 +5 /2";
    int res = sol.calculate(str);
    cout << res << endl;
    
    return 0;
}
