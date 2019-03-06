//
//  main.cpp
//  Round A - 1.Even Ditgits
//
//  Created by 边俊林 on 2019/3/5.
//  Copyright © 2019 边俊林. All rights reserved.
//

#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define ll long long

using namespace std;

/// Solution:
//

/// Tips:
// 两种可能：
// 1. 找到最高位的奇数，然后将其+1，后面的数全部置0。此为接近的最大值
// 2. 找到最高位的奇数，然后将其-1，后面的数全部置8。此为接近的最小值
// 有一个优化点：当寻找最大值时，如果该奇数为9，则需要考虑进位，但实际没必要考虑，因为进位后新进的位是1，又需要继续+1，会导致此最大值一定比最小值差距大，故答案直接返回最小值。

ll toNumber(string& num) {
    ll ans = 0;
    for (int i = 0; i < num.length(); ++i) {
        ans *= 10;
        ans += num[i] - '0';
    }
    return ans;
}

ll Upper(string& num, int oddIdx) {
    string tmpNum = string(num);
    if (tmpNum[oddIdx] == '9')
        return LONG_MAX;
    else
        tmpNum[oddIdx] += 1;
    for (int i = oddIdx+1; i < tmpNum.length(); ++i) {
        tmpNum[i] = '0';
    }
    return toNumber(tmpNum);
}

ll Lower(string& num, int oddIdx) {
    string tmpNum = string(num);
    tmpNum[oddIdx] -= 1;
    for (int i = oddIdx+1; i < tmpNum.length(); ++i) {
        tmpNum[i] = '8';
    }
    return toNumber(tmpNum);
}

ll TapTimes(ll n) {
    int oddIdx = -1;
    string num = to_string(n);
    for (int i = 0; i < num.length(); ++i) {
        if ((num[i] - '0') & 1) {
            oddIdx = i;
            break;
        }
    }
    if (oddIdx == -1) return 0;
    ll upper = Upper(num, oddIdx);
    ll lower = Lower(num, oddIdx);

    if (upper == LONG_MAX)
        return n - lower;
    else
        return (upper-n) > (n-lower) ? n-lower : upper-n;
}

int main() {
    int T;
    ll n;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> n;
        cout << "Case #" << i << ": " << TapTimes(n) << endl;
    }

    return 0;
}
