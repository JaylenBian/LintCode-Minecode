//
//  main.cpp
//  30. 插入区间
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
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if (intervals.size() == 0)
            return {newInterval};
        
        int left = newInterval.start, right = newInterval.end;
        int pLeft, pRight;
        pLeft = pRight = -1;
        vector<Interval> res;
        for (int i = 0; i < intervals.size(); ++i) {
            auto interval = intervals[i];
            if (interval.end < left || interval.start > right) {
                if (interval.start > right && right != -1) {
                    res.push_back(Interval(left, right));
                    left = right = -1;
                }
                res.push_back(Interval(interval.start, interval.end));
                continue;
            } else {
                left = min(left, interval.start);
                right = max(right, interval.end);
            }
        }
        if (right != -1) {
            res.push_back(Interval(left, right));
        }
        return res;
    }
    
private:
    
};

/// Tips:
// 先找到开始有重合的点，然后计算交集。
// PS：找重合点的过程可以用二分优化


int main() {
    
    Solution sol = Solution();
    vector<Interval> intervals = {
        Interval(1, 2),
        Interval(5, 9),
    };
    Interval newInterval = Interval(2, 5);
//    vector<Interval> intervals = {
//        Interval(1, 2),
//        Interval(5, 9),
//    };
//    Interval newInterval = Interval(3, 4);
    auto res = sol.insert(intervals, newInterval);
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << it->start << " - " << it->end << endl;
    }
    
    return 0;
}
