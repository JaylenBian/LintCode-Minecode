//
//  main.cpp
//  954. Insert Delete GetRandom O(1) - 允许重复
//
//  Created by 边俊林 on 2019/3/17.
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
class RandomizedCollection {
public:
    RandomizedCollection() {
        nums = vector<int>();
        mp = unordered_map<int, unordered_set<int>>();
    }

    bool insert(int val) {
        mp[val].insert((int)nums.size());
        nums.push_back(val);
        return mp[val].size() == 1;
    }

    bool remove(int val) {
        if (mp[val].empty()) return false;

        int idx = *mp[val].begin();
        mp[val].erase(idx);
        if (idx != nums.size()-1) {
            nums[idx] = nums[nums.size()-1];
            mp[nums[idx]].erase((int)nums.size()-1);
            mp[nums[idx]].insert(idx);
        }
        nums.pop_back();
        return true;
    }

    int getRandom() {
        if (nums.size() == 0) return -1;
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mp;
};

/// Tips:
// 相对于657，本题有一个细节就是当通过和最后一个点互换来删除某个点时，要更新最后一个点所对应的位置记录。

int main() {

    RandomizedCollection obj = RandomizedCollection();
    cout <<  (obj.insert(1) ? "true" : "false") << endl;
    cout <<  (obj.insert(1) ? "true" : "false") << endl;
    cout <<  (obj.remove(1) ? "true" : "false") << endl;
    cout <<  (obj.insert(2) ? "true" : "false") << endl;
    cout << obj.getRandom() << endl;
    cout << obj.getRandom() << endl;
    cout << obj.getRandom() << endl;
    cout << obj.getRandom() << endl;
    cout << obj.getRandom() << endl;

    return 0;
}
