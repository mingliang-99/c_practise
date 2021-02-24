//
//  main.cpp
//  tracking_code
//
//  Created by mingliang on 2021/2/17.
//

#include <iostream>
#include <string>
#include <vector>

/*
 两个栈实现，最大值，最小值
 */
using namespace::std;
题目
原文：

How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element? Push, pop and min should all operate in O(1) time.

译文：

实现一个栈，除了push和pop操作，还要实现min函数以返回栈中的最小值。 push，pop和min函数的时间复杂度都为O(1)。

解答
看到这个题目最直接的反应是用一个变量来保存当前栈的最小值，让我们来看看这样可行否？ 如果栈一直push那是没有问题，入栈元素如果比当前最小值还小，那就更新当前最小值。 可是如果pop掉的栈顶元素就是最小值，那么我们如何更新最小值呢？显然不太好办。 既然只用一个变量没法解决这个问题，那我们就增加变量。如果说每个结点除了保存当前的 值，另外再保存一个从该结点到栈底的结点中的最小值。那么，不论哪个结点成为了栈顶结 点，我们都有办法取得剩下的这些元素的最小值。代价是付出的空间多了一倍

#include <iostream>
using namespace std;

const int MAX_INT = ~(1<<31);//2147483647

typedef struct node{
    int val, min;
}node;

class StackWithMin{
public:
    StackWithMin(int size=1000){
        buf = new node[size];
        buf[0].min = MAX_INT;
        cur = 0;
    }
    ~StackWithMin(){
        delete[] buf;
    }
    void push(int val){
        buf[++cur].val = val;
        if(val<buf[cur-1].min) buf[cur].min = val;
        else buf[cur].min = buf[cur-1].min;
    }
    void pop(){
        --cur;
    }
    int top(){
        return buf[cur].val;
    }
    bool empty(){
        return cur==0;
    }
    int min(){
        return buf[cur].min;
    }

private:
    node *buf;
    int cur;
};

class stack{
public:
    stack(int size=1000){
        buf = new int[size];
        cur = -1;
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

private:
    int *buf;
    int cur;
};

//一个栈保存实际的数据，一个栈保存最小值
class StackWithMin1{
public:
    StackWithMin1(){

    }
    ~StackWithMin1(){

    }
    void push(int val){
        s1.push(val);
        if(val<=min())
            s2.push(val);
    }
    void pop(){
        if(s1.top()==min())
            s2.pop();
        s1.pop();
    }
    int top(){
        return s1.top();
    }
    bool empty(){
        return s1.empty();
    }
    int min(){
        if(s2.empty()) return MAX_INT;
        else return s2.top();
    }

private:
    stack s1, s2;
};
int main(){
    //cout<<MIN_INT<<endl;
    StackWithMin1 mystack;//StackWithMin mystack;
    for(int i=0; i<20; ++i)
        mystack.push(i);
    cout<<mystack.min()<<" "<<mystack.top()<<endl;
    mystack.push(-100);
    mystack.push(-100);
    cout<<mystack.min()<<" "<<mystack.top()<<endl;
    mystack.pop();
    cout<<mystack.min()<<" "<<mystack.top()<<endl;
    return 0;
}
