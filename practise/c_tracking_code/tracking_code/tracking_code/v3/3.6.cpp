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
题目
原文：

Write a program to sort a stack in ascending order. You should not make any assumptions about how the stack is implemented. The following are the only functions that should be used to write this program: push | pop | peek | isEmpty.

译文：

写程序将一个栈按升序排序。对这个栈是如何实现的，你不应该做任何特殊的假设。 程序中能用到的栈操作有：push | pop | peek | isEmpty。

解答
方案1：

使用一个附加的栈来模拟插入排序。将原栈中的数据依次出栈与附加栈中的栈顶元素比较， 如果附加栈为空，则直接将数据压栈。否则， 如果附加栈的栈顶元素大于从原栈中弹出的元素，则将附加栈的栈顶元素压入原栈。 一直这样查找直到附加栈为空或栈顶元素已经不大于该元素， 则将该元素压入附加栈。

#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

void Qsort(stack<int> &s){
    priority_queue< int,vector<int>,greater<int> > q;
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    while(!q.empty()){
        s.push(q.top());
        q.pop();
    }
}

stack<int> Ssort(stack<int> s){
    stack<int> t;
    while(!s.empty()){
        int data = s.top();//原栈栈顶
        s.pop();//原栈出栈
        while(!t.empty() && t.top()>data){
            s.push(t.top());
            t.pop();
        }
        t.push(data);
    }
    return t;
}
int main(){
    srand((unsigned)time(0));
    stack<int> s;

    for(int i=0; i<10; ++i)
        s.push((rand()%100));
    //s = Ssort(s);
    Qsort(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
