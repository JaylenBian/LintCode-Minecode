//
//  main.cpp
//  82. 落单的数
//
//  Created by 边俊林 on 2018/8/15.
//  Copyright © 2018 minecode. All rights reserved.
//


/* ------------------------------------------------- *\
 https://www.lintcode.com/problem/two-sum/description
 \* ------------------------------------------------- */

#include <map>
#include <set>
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
// Bit Operation

class Solution {
public:
    /**
     * @param A An integer array
     * @return An integer
     */
    int singleNumber(vector<int> &A) {
        int sum = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum ^= A[i];
        }
        return sum;
    }
};

// Tool Function List

int main() {
    
    Solution sol = Solution();
    vector<int> v = {1, 2, 2, 1, 3, 4, 3};
    int res = sol.singleNumber(v);
    cout << res << endl;
    
    return 0;
}

