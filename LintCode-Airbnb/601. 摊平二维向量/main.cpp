//
//  main.cpp
//  601. 摊平二维向量
//
//  Created by 边俊林 on 2018/8/25.
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

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        int cnt = 0;
        for (int i = 0; i < vec2d.size(); ++i) {
            for (auto item: vec2d[i]) {
                v.push_back(item);
                ++cnt;
            }
        }
        curr = 0;
        tot = cnt;
    }
    
    int next() {
        return v[curr++];
    }
    
    bool hasNext() {
        return curr < tot;
    }
private:
    vector<int> v;
    int curr;
    int tot;
};

int main() {
    
    return 0;
}
