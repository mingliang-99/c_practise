//
//  main.cpp
//  tracking_code
//
//  Created by mingliang on 2021/2/17.
//

#include <iostream>
#include <string>
#include <vector>

using namespace::std;

// 两个栈实现队列
/*
  有数据进入队列时，我们不去管第二个栈是否有数据，只管往第一个栈压栈即可。 当数据出队列时，如果第二个栈有数据，那就出栈。 因为此时第二个栈的栈顶元素即为队列的队首元素；如果第二个栈没有数据， 这才将第一个栈的数据出栈移动到第二个栈，然后第二个栈再出栈。这样一来， 逻辑上相当于将一个队列从中间切开，第一个栈从栈顶到栈底对应队列的队尾到切开处， 第二个栈从栈顶到栈底对应队列的队首到切开处。这样简单的修改， 可以减少许多不必要的数据移动，提高效率
*/

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    /** Push element x to the back of queue. */
    void push(int x) {
        stIn.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // 只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if (stOut.empty()) {
            // 从stIn导入数据直到stIn为空
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    /** Get the front element. */
    int peek() {
        int res = this->pop(); // 直接使用已有的pop函数
        stOut.push(res); // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};
