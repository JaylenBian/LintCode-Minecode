//
//  main.cpp
//  363. 接雨水
//
//  Created by 边俊林 on 2019/2/26.
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
    int trapRainWater(vector<int> &heights) {
        int maxIdx = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] > heights[maxIdx]) {
                maxIdx = i;
            }
        }
        
        int sum = 0;
        int maxHeight = 0;
        for (int i = 0; i < maxIdx; ++i) {
            if (maxHeight > heights[i]) {
                sum += maxHeight - heights[i];
            }
            maxHeight = max(maxHeight, heights[i]);
        }
        
        maxHeight = 0;
        for (int i = (int)heights.size()-1; i > maxIdx; --i) {
            if (maxHeight > heights[i]) {
                sum += maxHeight - heights[i];
            }
            maxHeight = max(maxHeight, heights[i]);
        }
        
        return sum;
    }
    
private:
    
};

/// Tips:
// 获取到中间最大值，然后从两边向中间遍历。可以避免边缘漏水的判断。

int main() {
    
    Solution sol = Solution();
    vector<int> heights = {0, 1, 0};
//    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int res = sol.trapRainWater(heights);
    cout << res << endl;
    
    return 0;
}
