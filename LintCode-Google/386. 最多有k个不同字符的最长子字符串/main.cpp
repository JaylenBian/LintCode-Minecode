//
//  main.cpp
//  386. 最多有k个不同字符的最长子字符串
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
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        if (s.length() == 0 || k == 0) return 0;
        
        unordered_map<char, int> mp;
        int maxLength = 0;
        int p = 0;
        for (int i = 0; i < s.length(); ++i) {
            while (p < s.length()) {
                if (mp.size() == k && mp.find(s[p]) == mp.end()) {
                    break;
                } else {
                    if (mp.find(s[p]) == mp.end()) mp[s[p]] = 0;
                    mp[s[p++]] += 1;
                }
            }
            maxLength = max(maxLength, p-i);
            if (mp[s[i]] == 1) {
                mp.erase(s[i]);
            } else {
                mp[s[i]] -= 1;
            }
        }
        return maxLength;
    }
    
private:
    
};

/// Tips:
// 双指针，将右指针尽可能右移，当到达k个字符时保存最大值。再继续移左指针，依次循环。

int main() {
    
    Solution sol = Solution();
//    string s = "eceba";
//    int k = 3;
//    string s = "WORLD";
//    int k = 4;
//    string s = "WORLD";
//    int k = 0;
    string s = "eqgkcwGFvjjmxutystqdfhuMblWbylgjxsxgnoh";
    int k = 16;
    int res = sol.lengthOfLongestSubstringKDistinct(s, k);
    cout << res << endl;
    
    return 0;
}
