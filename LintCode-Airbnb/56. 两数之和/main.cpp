//
//  main.cpp
//  56. 两数之和
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
// Two Pointers

class Solution {
public:
    /**
     * @param numbers An array of Integer
     * @param target target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> hash = {{numbers[0], 0}};
        
        for (int i = 1; i < numbers.size(); ++i) {
            if (hash.find(target - numbers[i]) != hash.end()) {
                vector<int> res = {hash[target-numbers[i]], i};
                return res;
            }
            hash[numbers[i]] = i;
        }
        return vector<int>();
    }
};

// Tool Function List
void printVector(vector<int> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c%d", it==v.begin() ? '\0' : ' ', *it);
    }
    printf("]\n");
}
void printVectors(vector<vector<int>> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printVector(*it);
    }
    printf("]\n");
}

int main() {
    
    Solution sol = Solution();
    vector<int> v = {2, 7, 11, 15};
    int target = 9;
    auto res = sol.twoSum(v, target);
    
    printVector(res);
    
    return 0;
}
