//
//  main.cpp
//  1623. 数组中的最小距离
//
//  Created by 边俊林 on 2019/2/23.
//  Copyright © 2019 边俊林. All rights reserved.
//

#include <iostream>

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
    vector<int> minimalDistance(vector<int> &a, vector<int> &b) {
        vector<int> res = vector<int>(b.size());
        sort(a.begin(), a.end());
        
        for (int i = 0; i < b.size(); ++i) {
            int idx = (int)(lower_bound(a.begin(), a.end(), b[i]) - a.begin());
            if (idx == 0) {
                res[i] = a[0];
            } else if (idx == a.size()) {
                res[i] = a.back();
            } else {
                if (a[idx] - b[i] < b[i] - a[idx-1]) {
                    res[i] = a[idx];
                } else {
                    res[i] = a[idx-1];
                }
            }
        }
        
        return res;
    }
    
private:
    
};

/// Tips:
// 通过二分查找，存在一个坑：通过找到最接近的数时，其有可能是倒数第二接近。
// 因为 a target b，二分查找有可能找到a或b，而另一个有可能才是最接近的。


int main() {
    
    Solution sol = Solution();
    vector<int> a = {5, 1, 2, 3};
    vector<int> b = {2, 4, 2};
    auto res = sol.minimalDistance(a, b);
    
    for (auto elem : res)
        cout << elem << endl;
    
    return 0;
}
