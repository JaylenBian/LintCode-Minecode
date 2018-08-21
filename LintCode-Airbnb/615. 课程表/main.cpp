//
//  main.cpp
//  615. 课程表
//
//  Created by 边俊林 on 2018/8/21.
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
    /*
     * @param numCourses a total of n courses
     * @param prerequisites a list of prerequisite pairs
     * @return true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // Init
        list<int> *adjs = new list<int>[numCourses];
        queue<int> q;
        int *indegree = new int[numCourses];
        memset(indegree, 0, numCourses * sizeof(int));
        for (int i = 0; i < prerequisites.size(); ++i) {
            pair<int, int> pir = prerequisites[i];
            int l = pir.first, r = pir.second;
            adjs[l].push_back(r);
            ++indegree[r];
        }
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        int outcnt = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            ++outcnt;
            for (list<int>::iterator it = adjs[v].begin(); it != adjs[v].end(); ++it) {
                if ((--indegree[*it] )== 0) q.push(*it);
            }
        }
        return outcnt == numCourses;
    }
};

int main() {
    
    return 0;
}
