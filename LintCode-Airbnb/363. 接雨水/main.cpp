//
//  main.cpp
//  363. 接雨水
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
     * @param heights a list of integers
     * @return a integer
     */
    int trapRainWater(vector<int> &heights) {
        int l = 0, r = (int)heights.size()-1;
        int sum = 0;
        while (l < r) {
            int minn = min(heights[l], heights[r]);
            if (minn == heights[l]) {
                l++;
                while (l<r && heights[l]<=minn) {
                    sum += minn - heights[l++];
                }
            } else {
                r--;
                while (l<r && heights[r]<=minn) {
                    sum += minn - heights[r--];
                }
            }
        }
        return sum;
    }
};

int main() {
    
    Solution sol = Solution();
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int res = sol.trapRainWater(v);
    cout << res << endl;
    return 0;
}
