//
//  main.cpp
//  657. Insert Delete GetRandom O(1)
//
//  Created by 边俊林 on 2019/2/21.
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
class RandomizedSet {
public:
    RandomizedSet() {
        posMap = unordered_map<int, int>();
        nums = vector<int>();
    }
    
    bool insert(int val) {
        if (posMap.find(val) != posMap.end())
            return false;
        
        nums.push_back(val);
        posMap[val] = (int)nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (posMap.find(val) == posMap.end())
            return false;
        
        int pos = posMap[val];
        nums[pos] = nums[nums.size()-1];
        nums.pop_back();
        posMap.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
    
private:
    unordered_map<int, int> posMap;
    vector<int> nums;
};

/// Tips:
// 通过哈希表可以实现O(1)时间内插入删除元素，用vector保存元素时，取元素时间也是O(1)，而存储和删除元素为队尾时也是O(1)
// 故可以通过哈希表存储元素在数组中的位置来完成random函数的O(1)复杂度，当删除时，通过将其和最后一个交换，然后删除最后一个，实现删除的O(1)复杂度。


int main() {
    
    RandomizedSet set = RandomizedSet();
    cout << set.insert(1) << endl;
    cout << set.insert(2) << endl;
    cout << set.insert(2) << endl;
    
    cout << set.remove(1) << endl;
    cout << set.remove(1) << endl;
    
    cout << set.insert(1) << endl;
    
    for (int i = 0; i < 10; ++i) {
        cout << set.getRandom() << "\t";
    }
    cout << endl;
    
    return 0;
}
