//
//  main.cpp
//  12. 带最小值操作的栈
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
class MinStack {
public:
    MinStack() {
        realStack = stack<int>();
        minStack = stack<int>();
    }
    
    void push(int number) {
        realStack.push(number);
        if (!minStack.empty() && minStack.top() < number) {
            minStack.push(minStack.top());
        } else {
            minStack.push(number);
        }
    }
    
    int pop() {
        int res = realStack.top();
        realStack.pop();
        minStack.pop();
        return res;
    }
    
    int min() {
        if (minStack.empty())
            throw new logic_error("No element is stack");
        return minStack.top();
    }
    
private:
    stack<int> realStack;
    stack<int> minStack;
};

/// Tips:
// 通过两个栈来实现，第一个保存栈的值，另一个保存当前栈顶元素对应的栈内最小值。


int main() {
    
    MinStack st = MinStack();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(0);
    
    cout << "Min: " << st.min() << endl;
    cout << "Pop: " << st.pop() << endl;
    cout << "Pop: " << st.pop() << endl;
    cout << "Min: " << st.min() << endl;
    
    return 0;
}
