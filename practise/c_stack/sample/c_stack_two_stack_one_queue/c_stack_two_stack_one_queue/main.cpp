//
//  main.cpp
//  c_stack_two_stack_one_queue
//
//  Created by mingliang on 2021/1/26.
//

#include <iostream>
#include <stack>
using namespace::std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // 只有当s2为空的时候，再从s1里导入数据（导入s1全部数据）
        if (s2.empty()) {
            // 从s1导入数据直到s1为空
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int result = s2.top();
        s2.pop();
        return result;
    }

    /** Get the front element. */
    int front() {
        int res = this->pop(); // 直接使用已有的pop函数
        s2.push(res); // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}



