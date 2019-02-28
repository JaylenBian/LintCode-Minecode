//
//  main.cpp
//  425. 电话号码的字母组合
//
//  Created by 边俊林 on 2019/2/28.
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
    vector<string> letterCombinations(string &digits) {
        if (digits.empty()) return {};
        
        vector<int> nums;
        for (int i = 0; i < digits.length(); ++i) {
            if (digits[i] >= '2' && digits[i] <= '9')
                nums.push_back(digits[i] - '0');
        }
        vector<string> res;
        vector<char> path;
        TypeNumber(nums, 0, path, res);
        return res;
    }
    
private:
    const vector<vector<char>> btn = {
        {}, {},
        {'a', 'b', 'c'}, {'d', 'e', 'f'},
        {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}
    };
    
    void TypeNumber(vector<int>& nums, int pos, vector<char>& path, vector<string>& res) {
        if (pos == nums.size()) {
            res.push_back(string(path.begin(), path.end()));
            return;
        }
        for (int i = 0; i < btn[nums[pos]].size(); ++i) {
            path.push_back(btn[nums[pos]][i]);
            TypeNumber(nums, pos+1, path, res);
            path.pop_back();
        }
    }
};

/// Tips:
//

int main() {
    
    Solution sol = Solution();
//    string digits = "23";
//    string digits = "";
    string digits = "5";
    auto res = sol.letterCombinations(digits);
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it << endl;
    }
    
    return 0;
}
