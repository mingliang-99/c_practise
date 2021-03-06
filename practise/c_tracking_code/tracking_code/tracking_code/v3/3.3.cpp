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
原文：

Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks, and should create a new stack once the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack (that is, pop() should return the same values as it would if there were just a single stack).

FOLLOW UP

Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.

译文：

栈就像叠盘子，当盘子叠得太高时，就会倾斜倒下。因此，在真实的世界中，当一叠盘子 (栈)超过了一定的高度时，我们就会另起一堆，再从头叠起。实现数据结构SetOfStacks 来模拟这种情况。SetOfStacks由几个栈组成，当前一栈超出容量时，需要创建一个新的栈 来存放数据。SetOfStacks.push()和SetOfStacks.pop()的行为应当和只有一个栈时 表现的一样。

进一步地，

实现函数popAt(int index)在指定的子栈上进行pop操作

解答
首先，我们如果不考虑popAt这个麻烦的函数，那么SetOfStacks的实现就简单很多。 SetOfStacks由栈的数组构成，我们需要一个指向当前栈的变量cur， 每当执行push操作时，我们需要检查一下当前栈是否已经达到其容量了， 如果是的话，就要将cur加1，指向下一个栈。而执行pop操作时， 需要先检查当前栈是否为空，如果是，则cur减1，移向上一个栈。top操作同理。 这时候，SetOfStacks可以想象成把一个本来可以叠得很高的栈，分成了好几个子栈。 push和pop操作其实都只是在“最后”一个子栈上操作。

代码如下

push 需要管理栈满的情况；
pop 需要管理栈空的情况；

#include <iostream>
using namespace std;

const int STACK_SIZE = 100;
const int STACK_NUM = 10;
class stack{
private:
    int *buf;
    int cur;
    int capacity;

public:
    stack(int capa = STACK_SIZE){
        buf = new int[capa];
        cur = -1;
        capacity = capa;
    }
    ~stack(){
        delete[] buf;
    }
    void push(int val){
        buf[++cur] = val;
    }
    void pop(){
        --cur;
    }
    int top(){
        return buf[cur];
    }
    bool empty(){
        return cur==-1;
    }
    bool full(){
        return cur==capacity-1;
    }
};

class SetOfStacks{//without popAt()
private:
    stack *st;
    int cur;
    int capacity;

public:
    SetOfStacks(int capa=STACK_NUM){
        st = new stack[capa];
        cur = 0;
        capacity = capa;
    }
    ~SetOfStacks(){
        delete[] st;
    }
    void push(int val){
        if(st[cur].full()) ++cur;
        st[cur].push(val);
    }
    void pop(){
        if(st[cur].empty()) --cur;
        st[cur].pop();
    }
    int top(){
        if(st[cur].empty()) --cur;
        return st[cur].top();
    }
    bool empty(){
        if(cur==0) return st[0].empty();
        else return false;
    }
    bool full(){
        if(cur==capacity-1) return st[cur].full();
        else return false;
    }
};
class SetOfStacks1{
private:
    stack *st;
    int cur; //记录当前是哪个栈
    int capacity;

public:
    SetOfStacks1(int capa=STACK_NUM){
        st = new stack[capa];
        cur = 0;
        capacity = capa;
    }
    ~SetOfStacks1(){
        delete[] st;
    }
    //入队检查是否满
    void push(int val){
        if(st[cur].full()) ++cur;
        st[cur].push(val);
    }
    //出队检查是否空
    void pop(){
        while(st[cur].empty()) --cur;
        st[cur].pop();
    }
    //检查是否空，如果空，需要递减下到下一个栈
    void popAt(int idx){
        while(st[idx].empty()) --idx;
        st[idx].pop();
    }
    int top(){
        while(st[cur].empty()) --cur;
        return st[cur].top();
    }
    bool empty(){
        while(cur!=-1 && st[cur].empty()) --cur;
        if(cur==-1) return true;
        else return false;
    }
    bool full(){
        if(cur==capacity-1) return st[cur].full();
        else return false;
    }
};
int main(){
    // SetOfStacks ss;
    // for(int i=0; i<STACK_SIZE+1; ++i){
    //     ss.push(i);
    // }
    // while(!ss.empty()){
    //     cout<<ss.top()<<endl;
    //     ss.pop();
    // }
    SetOfStacks1 ss1;
    for(int i=0; i<3*STACK_SIZE+1; ++i){
        ss1.push(i);
    }
    for(int i=0; i<STACK_SIZE; ++i){
        ss1.popAt(0);
        //ss1.popAt(1);
        ss1.popAt(2);
    }
    ss1.popAt(3);
    while(!ss1.empty()){
        cout<<ss1.top()<<endl;
        ss1.pop();
    }

    return 0;
}
