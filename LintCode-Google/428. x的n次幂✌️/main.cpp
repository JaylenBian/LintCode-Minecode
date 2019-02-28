//
//  main.cpp
//  428. x的n次幂
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
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;

        bool isNegative = false;
        if (n < 0) {
            isNegative = true;
        }
        double res;
        if (n & 1)
            res = x * myPow(x*x, isNegative ? -(n/2) : n/2);
        else
            res = myPow(x*x, isNegative ? -(n/2) : n/2);

        if (isNegative)
            return 1 / res;
        return res;
    }

private:

};

/// Tips:
// 二分法，要注意正负数组越界问题， -2147483648 这个情况如果直接负变正会越界。

int main() {

    Solution sol = Solution();
//    double x = 9.88023;
//    int n = 3;
//    double x = 0.44894;
//    int n = -5;
    double x = 2.00;
    int n = -2147483648;
    double res = sol.myPow(x, n);
    cout << res << endl;

    return 0;
}
