//
//  main.cpp
//  978. Basic Calculator
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
        int res = 0, sign = 1;
        stack<int> st;
        int n = (int)s.length();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c >= '0' && c<='9') {
                int num = 0;
                while (i<n && s[i]>='0' && s[i]<='9') {
                    num = num * 10 + (s[i++] - '0');
                }
                i--;
                res += sign * num;
            }
        }
        return res;
    }
};

int main() {
    
    Solution sol = Solution();
    string str = "(1+(4+5+2)-3)+(6+8)";
    int res = sol.calculate(str);
    cout << res << endl;
    
    return 0;
}
