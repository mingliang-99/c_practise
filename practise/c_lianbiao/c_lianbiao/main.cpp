#include <iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<sstream>
#include<cstring>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<list>
//
//  main.cpp
//  c_lianbiao
//
//  Created by mingliang on 2020/10/23.
//

/*
 基础数据结构
 */

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

/*
 链表刷题分类
 
 单链表
 1.遍历
 2.删除
 3.插入
 */

/*
  1. 链表遍历,返回
 */

ListNode* TraversalList(ListNode *head){
    ListNode *tmp;
    if(head == nullptr){
        return nullptr;
    }
    while (head != nullptr) {
        head = head->next;
        if(head){
            printf("check val=%d ",head->val);
        }
    }
}


#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
