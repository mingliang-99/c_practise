//
//  main.cpp
//  delete-middle-node-lcci
//
//  Created by mingliang on 2020/12/28.
//
/*
 [链接]  https://leetcode-cn.com/problems/delete-middle-node-lcci/
 [级别] easy
 [说明]   实现一种算法，删除单向链表中间的某个节点（即不是第一个或最后一个节点），假定你只能访问该节点
 [样例]  输入：单向链表a->b->c->d->e->f中的节点c
         结果：不返回任何数据，但该链表变为a->b->d->e->f
 [思路] 已知当前需要删除的节点，但无法删除这个节点，可以考虑一个能删除的代替这个一定不能删除的节点
       
 */
#include <iostream>

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

void deleteMiddleNodeLcci(ListNode *node){
    node->val = node->next->val;
    node->next = node->next->next;
}

int main(int argc, const char * argv[]) {
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
